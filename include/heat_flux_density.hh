#pragma once

#include <wither/units/area.hh>
#include <wither/units/power.hh>

namespace units
{

using watts_per_square_metre = impl::divide<watts, square_metres>;

namespace dimensions
{

using heat_flux_density = watts_per_square_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

