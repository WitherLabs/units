#pragma once

#include <mooncat/units/velocity>

namespace lmc::units::acceleration
{
using meters_per_second_squared
    = impl::cnt::unit_container<impl::def::definition_divide<
        velocity::meters_per_second::definition,
        time::seconds::definition>>;
ADD_PREFIXES_TO_CONTAINER(meters_per_second_squared)

using dimension = meters_per_second_squared::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_acceleration_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_acceleration_unit_v = is_acceleration_unit<container>::value;

using feet_per_second_squared
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::feet::definition,
        impl::def::definition_squared<time::seconds::definition>>>;

using knots_per_second = impl::cnt::unit_container<impl::def::definition_divide<
    velocity::knots::definition,
    time::seconds::definition>>;

} // namespace lmc::units::acceleration
