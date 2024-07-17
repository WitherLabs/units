// vim: set ft=cpp:

#pragma once

#include <mooncat/units/luminosity>
#include <mooncat/units/solid_angle>

namespace lmc::units::luminous_flux
{

using lumens = impl::cnt::unit_container<impl::def::definition_multiply<
    luminosity::candelas::definition,
    solid_angle::steradians::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(lumens)

using dimension = lumens::definition::dimension;

} // namespace lmc::units::luminous_flux

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(luminous_flux, lumens)
} // namespace ilmc
