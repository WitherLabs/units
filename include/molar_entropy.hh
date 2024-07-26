#pragma once

#include <wither/units/energy.hh>
#include <wither/units/substance.hh>
#include <wither/units/temperature.hh>

namespace units
{

using joules_per_mole_kelvin
    = impl::divide<joules, impl::multiply<moles, kelvins>>;
using joules_per_mole_celsius = impl::clone<joules_per_mole_kelvin>;

namespace dimensions
{

using molar_entropy = joules_per_mole_kelvin::magkind::dimension;

} // namespace dimensions

} // namespace units

