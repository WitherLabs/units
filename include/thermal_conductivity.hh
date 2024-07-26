#pragma once

#include <wither/units/power.hh>
#include <wither/units/temperature.hh>

namespace units
{

using watts_per_metre_kelvin
    = impl::divide<watts, impl::multiply<metres, kelvins>>;
using watts_per_metre_celsius = impl::clone<watts_per_metre_kelvin>;

namespace dimensions
{

using thermal_conductivity = watts_per_metre_kelvin::magkind::dimension;

} // namespace dimensions

} // namespace units

