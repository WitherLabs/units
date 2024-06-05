#pragma once

#include "dimension.hh"
#include "unit_components.hh"
#include "util.hh"

namespace lmc::units::impl::def
{

namespace check
{

namespace tag
{
struct unit_definition
{
};

struct unit_conversion
{
};
} // namespace tag

template <typename t>
using is_unit_definition = std::is_base_of<tag::unit_definition, t>;

template <typename t>
bool constexpr is_unit_definition_v = is_unit_definition<t>::value;

template <typename t>
using is_unit_conversion = std::is_base_of<tag::unit_conversion, t>;

template <typename t>
bool constexpr is_unit_conversion_v = is_unit_conversion<t>::value;

} // namespace check

namespace cpt
{
template <typename t>
concept unit_definition = requires {
    typename t::dimension;
    typename t::prefix;
    typename t::ratio;
    typename t::delta;
} && check::is_unit_definition_v<t>;

template <typename t>
concept unit_conversion = requires {
    typename t::to;
    typename t::from;
    typename t::prefix;
    typename t::ratio;
    typename t::delta;
} && check::is_unit_conversion_v<t>;
} // namespace cpt

template <
    dim::cpt::dimensional_vector dimension_t,
    cmp::cpt::unit_prefix        prefix_t,
    cmp::cpt::unit_ratio         ratio_t,
    cmp::cpt::unit_delta         delta_t>
struct unit_definition: check::tag::unit_definition
{
    using dimension = dimension_t;
    using prefix    = prefix_t;
    using ratio     = ratio_t;
    using delta     = delta_t;
};

template <util::cpt::ratio r, cpt::unit_definition to>
using derive_unit_ratio = cmp::derive_unit_ratio<r, typename to::ratio>;

template <cpt::unit_definition from, util::cpt::ratio to_delta>
using derive_unit_delta = cmp::derive_unit_delta<
    typename from::ratio,
    typename from::delta,
    cmp::unit_delta<to_delta>>;

template <cpt::unit_definition from, cpt::unit_definition to>
using convert_unit_prefix
    = cmp::convert_unit_prefix<typename from::prefix, typename to::prefix>;

template <cpt::unit_definition from, cpt::unit_definition to>
using convert_unit_ratio
    = cmp::convert_unit_ratio<typename from::ratio, typename to::ratio>;

template <cpt::unit_definition from, cpt::unit_definition to>
using convert_unit_delta
    = cmp::convert_unit_delta<typename from::delta, typename to::delta>;

template <cpt::unit_definition def_from, cpt::unit_definition def_to>
// requires def_from::dimension::template
// equals_v<def_to>
struct unit_conversion: check::tag::unit_conversion
{
    using from   = def_from;
    using to     = def_to;

    using prefix = convert_unit_prefix<from, to>;
    using ratio  = convert_unit_ratio<from, to>;
    using delta  = convert_unit_delta<from, to>;
};

template <cpt::unit_conversion t>
[[nodiscard]]
constexpr auto
apply_conversion(long double const measurement) noexcept -> long double
{
    return (
        t::ratio::value * ((measurement * t::prefix::value) + t::delta::value)
    );
}

template <cpt::unit_definition t, cmp::cpt::unit_prefix p>
using definition_with_different_prefix = unit_definition<
    typename t::dimension,
    p,
    typename t::ratio,
    typename t::delta>;

template <util::cpt::ratio r, cpt::unit_definition t>
using definition_with_derived_ratio = unit_definition<
    typename t::dimension,
    typename t::prefix,
    derive_unit_ratio<r, t>,
    typename t::delta>;

template <cpt::unit_definition a, cpt::unit_definition b>
using definition_multiply = unit_definition<
    typename a::dimension::template add<typename b::dimension>,
    convert_unit_prefix<a, b>,
    convert_unit_ratio<a, b>,
    convert_unit_delta<a, b>>;

template <cpt::unit_definition a, cpt::unit_definition b>
using definition_divide = unit_definition<
    typename a::dimension::template add<typename b::dimension>,
    convert_unit_prefix<a, b>,
    convert_unit_ratio<a, b>,
    convert_unit_delta<a, b>>;

} // namespace lmc::units::impl::def
