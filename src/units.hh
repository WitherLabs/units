#pragma once

#include "dimension.hh"
#include "util.hh"
#include <type_traits>

namespace lmc::units
{

namespace identification
{
struct unit_definition_tag
{
};

template <typename t>
using is_unit_definition = std::is_base_of<unit_definition_tag, t>;

struct unit_container_tag
{
};

template <typename t>
using is_unit_container = std::is_base_of<unit_container_tag, t>;

} // namespace identification

template <typename dim_vector, typename prefix_ratio, typename base_unit_ratio>
requires dimensional::identification::is_dimensional_vector<dim_vector>::value
      && util::is_ratio<prefix_ratio>::value
      && util::is_ratio<base_unit_ratio>::value
struct unit_definition: identification::unit_definition_tag
{
    using dimensions = dim_vector;
    using prefix     = prefix_ratio;
    using base_ratio = base_unit_ratio;
};

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

    [[nodiscard]]
    constexpr auto
    get_measurement() const noexcept -> long double
    {
        return _measurement;
    }

    template <typename unit_def_to>
    requires identification::is_unit_definition<unit_def_to>::value
    [[nodiscard]]
    constexpr auto
    convert_to() const noexcept -> unit_container<unit_def_to>
    {
        long double const this_prefix
            = util::convert_ratio_to_real<typename definition::prefix>();
        long double const this_base
            = util::convert_ratio_to_real<typename definition::base_ratio>();

        long double const other_prefix
            = util::convert_ratio_to_real<typename unit_def_to::prefix>();
        long double const other_base
            = util::convert_ratio_to_real<typename unit_def_to::base_ratio>();

        long double const final_prefix = this_prefix / other_prefix;
        long double const final_base   = this_base / other_base;

        return unit_container<unit_def_to> { final_prefix * _measurement
                                             / final_base };
    }

    template <typename unit_container_to>
    requires identification::is_unit_container<unit_container_to>::value
    [[nodiscard]]
    constexpr auto
    convert_to() const noexcept
        -> unit_container<typename unit_container_to::definition>
    {
        return convert_to<typename unit_container_to::definition>();
    }

private:
    long double _measurement;
};

} // namespace lmc::units
