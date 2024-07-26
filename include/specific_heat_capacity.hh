#pragma once

#include "units.hh"
#include <wither/units/energy.hh>
#include <wither/units/mass.hh>
#include <wither/units/temperature.hh>

namespace units
{

using joules_per_kilogram_kelvin
    = impl::divide<joules, impl::multiply<kilo<grams>, kelvins>>;
using joules_per_kilogram_celsius = impl::clone<joules_per_kilogram_kelvin>;

namespace dimensions
{

using specific_heat_capacity = joules_per_kilogram_kelvin::magkind::dimension;

} // namespace dimensions

} // namespace units

