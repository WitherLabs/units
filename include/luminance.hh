#pragma once

#include <wither/units/area.hh>
#include <wither/units/luminous_flux.hh>

namespace units
{

using candelas_per_square_metre = impl::divide<lumens, square_metres>;

namespace dimensions
{

using luminance = candelas_per_square_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

