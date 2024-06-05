#pragma once

#include "util.hh"
#include <type_traits>

namespace lmc::units::impl::cmp
{

namespace check
{

namespace tag
{
struct unit_prefix
{
};

struct unit_ratio
{
};

struct unit_delta
{
};
} // namespace tag

template <typename t>
using is_unit_prefix = std::is_base_of<tag::unit_prefix, t>;

template <typename t>
bool constexpr is_unit_prefix_v           = is_unit_prefix<t>::value;

template <typename t> using is_unit_ratio = std::is_base_of<tag::unit_ratio, t>;

template <typename t> bool constexpr is_unit_ratio_v = is_unit_ratio<t>::value;

template <typename t> using is_unit_delta = std::is_base_of<tag::unit_delta, t>;

template <typename t> bool constexpr is_unit_delta_v = is_unit_delta<t>::value;

} // namespace check

namespace cpt
{
template <typename t>
concept unit_prefix
    = check::is_unit_prefix_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept unit_ratio
    = check::is_unit_ratio_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept unit_delta
    = check::is_unit_delta_v<t> && util::cpt::has_internal_ratio<t>;
} // namespace cpt

template <util::cpt::ratio r> struct unit_prefix: check::tag::unit_prefix
{
    using ratio                        = std::ratio<r::num, r::den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r> struct unit_ratio: check::tag::unit_ratio
{
    using ratio                        = std::ratio<r::num, r::den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r> struct unit_delta: check::tag::unit_delta
{
    using ratio                        = std::ratio<r::num, r::den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

using base_unit_prefix = unit_prefix<std::ratio<1>>;
using base_unit_ratio  = unit_ratio<std::ratio<1>>;
using base_unit_delta  = unit_delta<std::ratio<0>>;

template <util::cpt::ratio r, cpt::unit_ratio to>
using derive_unit_ratio
    = unit_ratio<std::ratio_multiply<typename to::ratio, r>>;

template <
    cpt::unit_ratio ratio_from,
    cpt::unit_delta delta_from,
    cpt::unit_delta delta_to>
using derive_unit_delta = unit_delta<std::ratio_add<
    std::ratio_multiply<typename ratio_from::ratio, typename delta_from::ratio>,
    typename delta_to::ratio>>;

template <cpt::unit_prefix from, cpt::unit_prefix to>
using convert_unit_prefix
    = unit_prefix<std::ratio_divide<typename from::ratio, typename to::ratio>>;

template <cpt::unit_ratio from, cpt::unit_ratio to>
using convert_unit_ratio
    = unit_ratio<std::ratio_divide<typename from::ratio, typename to::ratio>>;

template <cpt::unit_delta delta_from, cpt::unit_delta delta_to>
using convert_unit_delta = unit_delta<
    std::ratio_subtract<typename delta_to::ratio, typename delta_from::ratio>>;

} // namespace lmc::units::impl::cmp
