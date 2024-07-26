#pragma once

#include <wither/units/energy.hh>
#include <wither/units/mass.hh>

namespace units
{

using grays    = impl::divide<joules, kilo<grams>>;
using sieverts = impl::clone<grays>;

namespace dimensions
{

using dose = grays::magkind::dimension;

} // namespace dimensions

} // namespace units

