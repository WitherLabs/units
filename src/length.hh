#pragma once

#include <ratio>

#include <mooncat/units/meta.hh>
#include <mooncat/units/prefixes.hh>
// ---
#include <mooncat/units/macros.hh>

namespace lmc::units {

namespace dimension {

using length = unit_dimensions<power::length<1, 1>,
                               power::time<0, 1>,
                               power::mass<0, 1>,
                               power::substance<0, 1>,
                               power::luminous<0, 1>,
                               power::temperature<0, 1>,
                               power::current<1, 1>>;

} // namespace dimension

LMC_DEFINE_UNIT_WHOLE(meter, meters, length, 1, 1)

LMC_DEFINE_UNIT_WHOLE_WRT(foot, feet, length, 381, 1250, meter)
LMC_DEFINE_UNIT_WHOLE_WRT(twip, twips, length, 1, 17280, foot)
LMC_DEFINE_UNIT_WHOLE_WRT(thou, thous, length, 1, 12000, foot)
LMC_DEFINE_UNIT_WHOLE_WRT(barleycorn, barleycorns, length, 1, 36, foot)
LMC_DEFINE_UNIT_WHOLE_WRT(inch, inches, length, 3, 1, barleycorn)
LMC_DEFINE_UNIT_WHOLE_WRT(hand, hands, length, 4, 1, inch)
LMC_DEFINE_UNIT_WHOLE_WRT(yard, yards, length, 3, 1, foot)
LMC_DEFINE_UNIT_WHOLE_WRT(chain, chains, length, 22, 1, yard)
LMC_DEFINE_UNIT_WHOLE_WRT(furlong, furlongs, length, 10, 1, chain)
LMC_DEFINE_UNIT_WHOLE_WRT(mile, miles, length, 5280, 1, furlong)
LMC_DEFINE_UNIT_WHOLE_WRT(league, leagues, length, 3, 1, mile)

} // namespace lmc::units
