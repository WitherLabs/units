#pragma once

#include <wither/units/energy.hh>
#include <wither/units/substance.hh>
#include <wither/units/temperature.hh>

namespace units
{

using joules_per_mole_kelvin
    = impl::divide<joules, impl::multiply<moles, kelvins>>;

namespace dimensions
{

using molar_heat_capacity = joules_per_mole_kelvin::magkind::dimension;

} // namespace dimensions

} // namespace units

