#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(current, length<0>, mass<0>, time<0>, current<1>, temperature<0>, luminosity<0>, substance<0>)

LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    current,
    amperes,
    lmc::units::ratios::unit_base_ratio,
    lmc::units::ratios::unit_base_delta
)
