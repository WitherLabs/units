#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(length, length<1>, mass<0>, time<0>, current<0>, temperature<0>, luminosity<0>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    meters,
    lmc::units::ratios::unit_base_ratio
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    feet,
    (lmc::units::ratios::unit_ratio_wrt<381, 1250, meters>)
)

LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    twips,
    (lmc::units::ratios::unit_ratio_wrt<1, 17280, feet>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    thous,
    (lmc::units::ratios::unit_ratio_wrt<1, 12000, feet>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    barleycorns,
    (lmc::units::ratios::unit_ratio_wrt<1, 36, feet>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    inches,
    (lmc::units::ratios::unit_ratio_wrt<3, 1, barleycorns>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    hands,
    (lmc::units::ratios::unit_ratio_wrt<4, 1, inches>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    yards,
    (lmc::units::ratios::unit_ratio_wrt<3, 1, feet>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    chains,
    (lmc::units::ratios::unit_ratio_wrt<22, 1, yards>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    furlongs,
    (lmc::units::ratios::unit_ratio_wrt<10, 1, chains>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    miles,
    (lmc::units::ratios::unit_ratio_wrt<8, 1, furlongs>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    leagues,
    (lmc::units::ratios::unit_ratio_wrt<3, 1, miles>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    fathoms,
    (lmc::units::ratios::unit_ratio_wrt<463, 250, meters>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    cables,
    (lmc::units::ratios::unit_ratio_wrt<100, 1, fathoms>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    nautical_miles,
    (lmc::units::ratios::unit_ratio_wrt<10, 1, cables>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    links,
    (lmc::units::ratios::unit_ratio_wrt<66, 100, feet>)
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    length,
    rods,
    (lmc::units::ratios::unit_ratio_wrt<25, 1, links>)
)

