#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(mass, length<0>, mass<1>, time<0>, current<0>, temperature<0>, luminosity<0>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    grams,
    lmc::units::ratios::unit_base_ratio
)
