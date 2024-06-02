#pragma once

#include "macros.hh"
#include "unit_definition.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(temperature, length<0>, mass<0>, time<0>, current<1>, temperature<1>, luminosity<0>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    temperature,
    kelvins,
    lmc::units::ratios::unit_base_ratio,
    lmc::units::ratios::unit_base_delta
)

LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    temperature,
    celsius,
    (lmc::units::ratios::unit_ratio_wrt<1, 1, kelvins>),
    (std::ratio<-27315, 100>)
)

LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    temperature,
    fahrenheit,
    (lmc::units::ratios::unit_ratio_wrt<5, 9, celsius>),
    (lmc::units::ratios::unit_delta_wrt<160, 9, celsius>)
)

