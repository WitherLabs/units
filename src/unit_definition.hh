#pragma once

#include "dimension.hh"
#include "util.hh"
#include <type_traits>

#include <cstdint>

namespace lmc::units
{

namespace identification
{
struct unit_definition_tag
{
};

template <typename t>
using is_unit_definition = std::is_base_of<unit_definition_tag, t>;

} // namespace identification

template <
    typename dimensions_t,
    typename prefix_t,
    typename unit_ratio_t,
    typename delta_t>
requires dimensional::identification::is_dimensional_vector<dimensions_t>::value
      && util::is_ratio<prefix_t>::value && util::is_ratio<unit_ratio_t>::value
      && util::is_ratio<delta_t>::value
struct unit_definition: identification::unit_definition_tag
{
    using dimensions = dimensions_t;
    using prefix     = prefix_t;
    using unit_ratio = unit_ratio_t;
    using delta      = delta_t;
};

template <
    typename base_unit_t,
    typename prefix_t,
    typename unit_ratio_t,
    typename delta_t>
requires identification::is_unit_definition<base_unit_t>::value
          && util::is_ratio<prefix_t>::value
          && util::is_ratio<unit_ratio_t>::value
          && util::is_ratio<delta_t>::value
using derived_unit_definition = unit_definition<
    typename base_unit_t::dimensions,
    std::ratio_multiply<typename base_unit_t::prefix, prefix_t>,
    std::ratio_multiply<typename base_unit_t::unit_ratio, unit_ratio_t>,
    std::ratio_add<
        std::ratio_multiply<typename base_unit_t::unit_ratio, delta_t>,
        typename base_unit_t::delta>>;

namespace ratios
{
using unit_base_ratio  = std::ratio<1>;
using unit_base_prefix = std::ratio<1>;
using unit_base_delta  = std::ratio<0>;

template <std::intmax_t num, std::intmax_t den, typename wrt_definition>
requires identification::is_unit_definition<wrt_definition>::value
using unit_ratio_wrt = std::
    ratio_multiply<typename wrt_definition::unit_ratio, std::ratio<num, den>>;

template <std::intmax_t num, std::intmax_t den, typename wrt_definition>
requires identification::is_unit_definition<wrt_definition>::value
using unit_delta_wrt = std::ratio_add<
    std::ratio_multiply<
        typename wrt_definition::unit_ratio,
        std::ratio<num, den>>,
    typename wrt_definition::delta>;
} // namespace ratios

namespace conversion
{

template <typename unit_definition_from, typename unit_definition_to>
requires identification::is_unit_definition<unit_definition_from>::value
      && identification::is_unit_definition<unit_definition_to>::value
      && dimensional::are_dimensional_vectors_equal<
             typename unit_definition_from::dimensions,
             typename unit_definition_to::dimensions>::value
[[nodiscard]]
constexpr auto
get_conversion_factor_between_definitions() noexcept -> long double
{
    using resultant = std::ratio_multiply<
        std::ratio_divide<
            typename unit_definition_from::prefix,
            typename unit_definition_to::prefix>,
        std::ratio_divide<
            typename unit_definition_from::unit_ratio,
            typename unit_definition_to::unit_ratio>>;

    return static_cast<long double>(resultant::num)
         / static_cast<long double>(resultant::den);
}
} // namespace conversion

} // namespace lmc::units
