#pragma once

#include <wither/units/acceleration.hh>
#include <wither/units/mass.hh>

namespace units
{

using newtons = impl::multiply<kilo<grams>, metres_per_second_squared>;

namespace dimensions
{

using force = newtons::magkind::dimension;

} // namespace dimensions

} // namespace units

