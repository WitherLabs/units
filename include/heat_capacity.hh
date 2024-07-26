#pragma once

#include <wither/units/energy.hh>
#include <wither/units/temperature.hh>

namespace units
{

using joules_per_kelvin = impl::divide<joules, kelvins>;

namespace dimensions
{

using heat_capacity = joules_per_kelvin::magkind::dimension;

} // namespace dimensions

} // namespace units

