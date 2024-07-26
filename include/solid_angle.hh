#pragma once

#include <wither/units/area.hh>

namespace units
{

using steradians = impl::divide<square_metres, square_metres>;

namespace dimensions
{

using solid_angle = steradians::magkind::dimension;

} // namespace dimensions

} // namespace units

