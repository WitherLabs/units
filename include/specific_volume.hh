#pragma once

#include <wither/units/mass.hh>
#include <wither/units/volume.hh>h>h>

namespace units
{

using cubic_metres_per_kilogram = impl::divide<cubic_metres, kilo<grams>>;

namespace dimensions
{

using specific_volume = cubic_metres_per_kilogram::magkind::dimension;

} // namespace dimensions

} // namespace units

