#pragma once

#include <wither/units/length.hh>

namespace units
{

using radians = impl::divide<metres, metres>;

namespace dimensions
{

using plane_angle = radians::magkind::dimension;

} // namespace dimensions

} // namespace units

