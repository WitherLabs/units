// vim: set ft=cpp:

#pragma once

#include <mooncat/units/time>

namespace lmc::units::frequency
{
using hertz = impl::cnt::unit_container<
    impl::def::definition_reciprocate<time::seconds::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(hertz)

using dimension = hertz::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_frequency_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_frequency_unit_v = is_frequency_unit<container>::value;

} // namespace lmc::units::frequency
  //

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(frequency, hertz)
} // namespace ilmc
