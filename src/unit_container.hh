#pragma once

#include "unit_definition.hh"
#include "util.hh"

#include <ratio>

namespace lmc::units
{
namespace identification
{

struct unit_container_tag
{
};

template <typename t>
using is_unit_container = std::is_base_of<unit_container_tag, t>;
} // namespace identification

template <typename unit_def>
requires identification::is_unit_definition<unit_def>::value
class unit_container: identification::unit_container_tag
{
public:
    using definition = unit_def;

    explicit constexpr unit_container(long double measurement)
    : _measurement { measurement }
    {
    }

    template <typename unit_container_to>
    requires identification::is_unit_container<unit_container_to>::value
          && dimensional::are_dimensional_vectors_equal<
                 typename definition::dimensions,
                 typename unit_container_to::definition::dimensions>::value
    [[nodiscard]]
    constexpr auto
    get_conversion_factor_to() const noexcept -> long double
    {
        return conversion::get_conversion_factor_between_definitions<
            definition,
            typename unit_container_to::definition>();
    }

    template <typename unit_container_to>
    requires identification::is_unit_container<unit_container_to>::value
          && dimensional::are_dimensional_vectors_equal<
                 typename definition::dimensions,
                 typename unit_container_to::definition::dimensions>::value
    [[nodiscard]]
    constexpr auto
    get_delta_to() const noexcept -> long double
    {
        return util::convert_ratio_to_real<std::ratio_subtract<
            typename unit_container_to::definition::delta,
            typename definition::delta>>();
    }

    template <typename unit_container_to>
    requires identification::is_unit_container<unit_container_to>::value
          && dimensional::are_dimensional_vectors_equal<
                 typename definition::dimensions,
                 typename unit_container_to::definition::dimensions>::value
    [[nodiscard]]
    constexpr auto
    convert_to() const noexcept -> unit_container_to
    {
        return unit_container_to {
            this->get_conversion_factor_to<unit_container_to>()
            * (_measurement + this->get_delta_to<unit_container_to>())
        };
    }

    template <typename unit_container_to>
    requires identification::is_unit_container<unit_container_to>::value
          && dimensional::are_dimensional_vectors_equal<
                 typename definition::dimensions,
                 typename unit_container_to::definition::dimensions>::value
    [[nodiscard]] constexpr
    // NOLINTNEXTLINE // we do not want to mark this as explicit
    operator unit_container_to () const noexcept
    {
        return this->convert_to<unit_container_to>();
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

} // namespace lmc::units

