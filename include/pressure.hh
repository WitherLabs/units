#pragma once

#include <wither/units/area.hh>
#include <wither/units/force.hh>

namespace units
{

using pascals = impl::multiply<newtons, square_metres>;

namespace dimensions
{

using pressure = pascals::magkind::dimension;

} // namespace dimensions

} // namespace units

