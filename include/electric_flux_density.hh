#pragma once

#include <wither/units/area.hh>
#include <wither/units/charge.hh>

namespace units
{

using coulombs_per_square_metre = impl::divide<coulombs, square_metres>;

namespace dimensions
{

using electric_flux_density = coulombs_per_square_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

