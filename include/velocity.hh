// vim: set ft=cpp:

#pragma once

#include <mooncat/units/length>
#include <mooncat/units/time>

namespace lmc::units::velocity
{
using meters_per_second
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::meters::definition,
        time::seconds::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(meters_per_second)

using dimension = meters_per_second::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_velocity_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_velocity_unit_v = is_velocity_unit<container>::value;

using meters_per_hour = impl::cnt::unit_container<impl::def::definition_divide<
    length::kilometers::definition,
    time::hours::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(meters_per_hour)

using miles_per_hour = impl::cnt::unit_container<impl::def::definition_divide<
    length::miles::definition,
    time::hours::definition>>;

using inches_per_second
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::inches::definition,
        time::seconds::definition>>;

using feet_per_second = impl::cnt::unit_container<impl::def::definition_divide<
    length::feet::definition,
    time::seconds::definition>>;

using knots = impl::cnt::unit_container<impl::def::definition_divide<
    length::nautical_miles::definition,
    time::hours::definition>>;

} // namespace lmc::units::velocity

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(velocity, meters_per_second)
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(velocity, meters_per_hour)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(velocity, miles_per_hour)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(velocity, inches_per_second)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(velocity, feet_per_second)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(velocity, knots)
} // namespace ilmc

