#pragma once

#include <wither/units/power.hh>
#include <wither/units/solid_angle.hh>

namespace units
{

using watts_per_square_metre_steradian
    = impl::divide<watts, impl::multiply<square_metres, steradians>>;

namespace dimensions
{

using radiance = watts_per_square_metre_steradian::magkind::dimension;

} // namespace dimensions

} // namespace units

