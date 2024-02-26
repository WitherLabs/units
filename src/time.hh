
#pragma once

#include <ratio>

#include <mooncat/units/meta.hh>
#include <mooncat/units/prefixes.hh>
// ---
#include <mooncat/units/macros.hh>

namespace lmc::units {

namespace dimension {

using time = unit_dimensions<power::length<0, 1>,
                             power::time<1, 1>,
                             power::mass<0, 1>,
                             power::substance<0, 1>,
                             power::luminous<0, 1>,
                             power::temperature<0, 1>,
                             power::current<1, 1>>;

} // namespace dimension

LMC_DEFINE_UNIT_WHOLE(second, seconds, time, 1, 1)
LMC_DEFINE_UNIT_WHOLE_WRT(minute, minutes, time, 60, 1, second)
LMC_DEFINE_UNIT_WHOLE_WRT(hour, hours, time, 60, 1, minute)
LMC_DEFINE_UNIT_WHOLE_WRT(day, days, time, 24, 1, hour)
LMC_DEFINE_UNIT_WHOLE_WRT(week, weeks, time, 7, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(month_28d, months_28d, time, 28, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(month_29d, months_29d, time, 29, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(month_30d, months_30d, time, 30, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(month_31d, months_31d, time, 31, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(quarantine, quaranties, time, 40, 1, day)

LMC_DEFINE_UNIT_WHOLE_WRT(lunar_year, lunar_years, time, 35437, 100, day)
LMC_DEFINE_UNIT_WHOLE_WRT(common_year, common_years, time, 365, 1, day)
LMC_DEFINE_UNIT_WHOLE_WRT(leap_year, leap_years, time, 366, 1, day)

} // namespace lmc::units
