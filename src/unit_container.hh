#pragma once

#include "unit_definition.hh"

namespace lmc::units::impl::cnt
{
namespace check
{

namespace tag
{
struct unit_container
{
};
} // namespace tag

template <typename t>
using is_unit_container = std::is_base_of<tag::unit_container, t>;

template <typename t>
bool constexpr is_unit_container_v = is_unit_container<t>::value;
} // namespace check

namespace cpt
{
template <typename t>
concept unit_container
    = requires { typename t::definition; } && check::is_unit_container_v<t>;

} // namespace cpt

template <def::cpt::unit_definition unit_def>
class unit_container: check::tag::unit_container
{
public:
    using definition = unit_def;

    explicit constexpr unit_container(long double measurement)
    : _measurement { measurement }
    {
    }

    explicit constexpr unit_container()
    : _measurement { 0.0L }
    {
    }

    template <cpt::unit_container unit_container_to>
    requires unit_container_to::definition::dimension::template
    equals_v<typename definition::dimension> constexpr auto
    convert_to() const noexcept -> unit_container_to
    {
        using conversion = def::
            unit_conversion<definition, typename unit_container_to::definition>;
        return unit_container_to {
            def::apply_conversion<conversion>(_measurement)
        };
    }

    template <cpt::unit_container unit_container_to>
    requires unit_container_to::definition::dimension::template
    equals_v<typename definition::dimension> [[nodiscard]] constexpr
    // NOLINTNEXTLINE // we do not want to mark this as explicit
    operator unit_container_to () const noexcept
    {
        return this->convert_to<unit_container_to>();
    }

    template <cpt::unit_container other_unit_container>
    requires other_unit_container::definition::dimension::template
    equals_v<typename definition::dimension> [[nodiscard]]
    constexpr auto
    operator+ (other_unit_container container) const noexcept -> unit_container
    {
        return unit_container {
            _measurement
            + container.template convert_to<unit_container>()._measurement
        };
    }

    template <cpt::unit_container other_unit_container>
    requires other_unit_container::definition::dimension::template
    equals_v<typename definition::dimension> [[nodiscard]]
    constexpr auto
    operator- (other_unit_container container) const noexcept -> unit_container
    {
        return unit_container {
            _measurement
            - container.template convert_to<unit_container>().get_measurement()
        };
    }

    [[nodiscard]]
    constexpr auto
    get_measurement() const noexcept -> long double

    {
        return _measurement;
    }

private:
    long double _measurement;
};

template <cpt::unit_container t, cmp::cpt::unit_prefix p>
using container_with_different_prefix = unit_container<
    def::definition_with_different_prefix<typename t::definition, p>>;

template <util::cpt::ratio r, cpt::unit_container t>
using container_with_derived_ratio = unit_container<
    def::definition_with_derived_ratio<r, typename t::definition>>;

} // namespace lmc::units::impl::cnt

namespace lmc::units::impl::abbr
{
template <util::cpt::ratio r, cnt::cpt::unit_container t>
using derive = impl::cnt::container_with_derived_ratio<r, t>;
} // namespace lmc::units::impl::abbr

