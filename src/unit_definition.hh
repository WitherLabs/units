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

template <typename t>
bool constexpr is_unit_definition_v = is_unit_definition<t>::value;

} // namespace identification

template <
    typename dimensions_t,
    typename prefix_t,
    typename unit_ratio_t,
    typename delta_t>
requires dimensional::identification::is_dimensional_vector_v<dimensions_t>
      && util::is_ratio_v<prefix_t> && util::is_ratio_v<unit_ratio_t>
      && util::is_ratio_v<delta_t>
struct unit_definition: identification::unit_definition_tag
{
    using dimensions = dimensions_t;
    using prefix     = prefix_t;
    using unit_ratio = unit_ratio_t;
    using delta      = delta_t;
};

namespace ratios
{

template <std::intmax_t num, std::intmax_t den = 1>
using unit_prefix = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den = 1>
using unit_ratio = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den = 1>
using unit_delta       = std::ratio<num, den>;

using base_unit_prefix = unit_prefix<1>;
using base_unit_ratio  = unit_ratio<1>;
using base_unit_delta  = unit_delta<0>;

template <std::intmax_t num, std::intmax_t den, typename wrt_definition>
requires identification::is_unit_definition_v<wrt_definition>
using unit_prefix_wrt = std::
    ratio_multiply<typename wrt_definition::unit_ratio, std::ratio<num, den>>;

template <std::intmax_t num, std::intmax_t den, typename wrt_definition>
requires identification::is_unit_definition_v<wrt_definition>
using unit_ratio_wrt = std::
    ratio_multiply<typename wrt_definition::unit_ratio, std::ratio<num, den>>;

template <std::intmax_t num, std::intmax_t den, typename wrt_definition>
requires identification::is_unit_definition_v<wrt_definition>
using unit_delta_wrt = std::ratio_add<
    std::ratio_multiply<
        typename wrt_definition::unit_ratio,
        std::ratio<num, den>>,
    typename wrt_definition::delta>;
} // namespace ratios

template <
    typename base_unit_t,
    typename prefix_t,
    typename unit_ratio_t,
    typename delta_t>
requires identification::is_unit_definition_v<base_unit_t>
          && util::is_ratio_v<prefix_t> && util::is_ratio_v<unit_ratio_t>
          && util::is_ratio_v<delta_t>
using derived_unit_definition = unit_definition<
    typename base_unit_t::dimensions,
    ratios::unit_prefix_wrt<
        prefix_t::num,
        prefix_t::den,
        typename base_unit_t::prefix>,
    ratios::unit_ratio_wrt<
        prefix_t::num,
        prefix_t::den,
        typename base_unit_t::unit_ratio>,
    ratios::unit_delta_wrt<
        prefix_t::num,
        prefix_t::den,
        typename base_unit_t::delta>>;

namespace conversion
{

template <typename unit_definition_from, typename unit_definition_to>
requires identification::is_unit_definition_v<unit_definition_from>
      && identification::is_unit_definition_v<unit_definition_to>
      && dimensional::dimensional_vectors_are_equal_v<
             typename unit_definition_from::dimensions,
             typename unit_definition_to::dimensions>
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
