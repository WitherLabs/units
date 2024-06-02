#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(luminosity, length<0>, mass<0>, time<0>, current<0>, temperature<0>, luminosity<1>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    luminosity,
    candelas,
    lmc::units::ratios::unit_base_ratio,
    lmc::units::ratios::unit_base_delta
)
