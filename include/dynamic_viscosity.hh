#pragma once

#include <wither/units/pressure.hh>
#include <wither/units/time.hh>

namespace units
{

using pascal_seconds = impl::multiply<pascals, seconds>;

namespace dimensions
{

using dynamic_viscosity = pascal_seconds::magkind::dimension;

} // namespace dimensions

} // namespace units

