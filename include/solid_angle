// vim: set ft=cpp:

#pragma once

#include <mooncat/units/angle>

namespace lmc::units::solid_angle
{

using steradians = impl::cnt::unit_container<
    impl::def::definition_squared<angle::radians::definition>>;

using dimension = steradians::definition::dimension;

} // namespace lmc::units::solid_angle

inline namespace ilmc
{
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(solid_angle, steradians)
} // namespace ilmc

