#pragma once

#include <wither/units/energy.hh>
#include <wither/units/mass.hh>

namespace units
{

using joules_per_kilogram = impl::divide<joules, kilo<grams>>;

namespace dimensions
{

using specific_energy = joules_per_kilogram::magkind::dimension;

} // namespace dimensions

} // namespace units

