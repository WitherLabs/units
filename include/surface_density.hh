#pragma once

#include <wither/units/area.hh>
#include <wither/units/mass.hh>

namespace units
{

using kilograms_per_square_metre = impl::divide<kilo<grams>, square_metres>;

namespace dimensions
{

using volumetric_flow_rate = kilograms_per_square_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

