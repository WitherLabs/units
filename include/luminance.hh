#pragma once

#include <wither/units/area.hh>
#include <wither/units/luminous_flux.hh>

namespace units
{

using luxes = impl::divide<lumens, square_metres>;

namespace dimensions
{

using illuminance = luxes::magkind::dimension;

} // namespace dimensions

} // namespace units

