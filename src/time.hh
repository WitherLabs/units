#pragma once

#include "macros.hh"

LMC_UNITS_DEFINE_UNIT_FRAMEWORK(time, length<0>, mass<0>, time<1>, current<0>, temperature<0>, luminosity<0>, substance<0>)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    seconds,
    lmc::units::ratios::base_unit_ratio,
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    minutes,
    (lmc::units::ratios::unit_ratio_wrt<60, 1, seconds>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    hours,
    (lmc::units::ratios::unit_ratio_wrt<60, 1, minutes>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    days,
    (lmc::units::ratios::unit_ratio_wrt<24, 1, hours>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    weeks,
    (lmc::units::ratios::unit_ratio_wrt<7, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    months_28,
    (lmc::units::ratios::unit_ratio_wrt<28, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    months_29,
    (lmc::units::ratios::unit_ratio_wrt<29, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    months_30,
    (lmc::units::ratios::unit_ratio_wrt<30, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    months_31,
    (lmc::units::ratios::unit_ratio_wrt<31, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    year,
    (lmc::units::ratios::unit_ratio_wrt<365, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    leap_year,
    (lmc::units::ratios::unit_ratio_wrt<366, 1, days>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    decade,
    (lmc::units::ratios::unit_ratio_wrt<10, 1, year>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    century,
    (lmc::units::ratios::unit_ratio_wrt<100, 1, year>),
    lmc::units::ratios::base_unit_delta
)
LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(
    time,
    eon,
    (lmc::units::ratios::unit_ratio_wrt<1000000000, 1, year>),
    lmc::units::ratios::base_unit_delta
)
