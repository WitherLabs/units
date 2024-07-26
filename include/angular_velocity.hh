#pragma once

#include <wither/units/plane_angle.hh>
#include <wither/units/time.hh>

namespace units
{

using radians_per_second = impl::divide<radians, seconds>;

namespace dimensions
{

using angular_velocity = radians_per_second::magkind::dimension;

} // namespace dimensions

} // namespace units

