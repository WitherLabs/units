#pragma once

#include <wither/units/energy.hh>
#include <wither/units/substance.hh>

namespace units
{

using joules_per_mole = impl::divide<joules, moles>;

namespace dimensions
{

using molar_energy = joules_per_mole::magkind::dimension;

} // namespace dimensions

} // namespace units

