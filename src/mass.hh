#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(mass, length<0>, mass<1>, time<0>, current<0>, temperature<0>, luminosity<0>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    grams,
    lmc::units::ratios::base_unit_ratio,
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    pounds,
    (lmc::units::ratios::unit_ratio_wrt<45359237, 100000000, kilograms>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    grains,
    (lmc::units::ratios::unit_ratio_wrt<1, 7000, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    drachms,
    (lmc::units::ratios::unit_ratio_wrt<1, 256, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    ounces,
    (lmc::units::ratios::unit_ratio_wrt<1, 16, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    stones,
    (lmc::units::ratios::unit_ratio_wrt<14, 1, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    quarters,
    (lmc::units::ratios::unit_ratio_wrt<28, 1, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    hundredweights,
    (lmc::units::ratios::unit_ratio_wrt<112, 1, pounds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    mass,
    tons,
    (lmc::units::ratios::unit_ratio_wrt<2240, 1, pounds>),
    lmc::units::ratios::base_unit_delta
)
