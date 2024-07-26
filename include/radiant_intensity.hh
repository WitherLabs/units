#pragma once

#include <wither/units/power.hh>
#include <wither/units/solid_angle.hh>

namespace units
{

using watts_per_steradian = impl::divide<watts, steradians>;

namespace dimensions
{

using radiant_intensity = watts_per_steradian::magkind::dimension;

} // namespace dimensions

} // namespace units

