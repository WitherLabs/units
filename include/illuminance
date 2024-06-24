// vim: set ft=cpp:

#pragma once

#include <mooncat/units/luminous_flux>

namespace lmc::units::illuminance
{

using luxes = impl::cnt::unit_container<impl::def::definition_divide<
    luminous_flux::lumens::definition,
    impl::def::definition_squared<length::meters::definition>>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(luxes)

using dimension = luxes::definition::dimension;

} // namespace lmc::units::illuminance

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(illuminance, luxes)
} // namespace ilmc
