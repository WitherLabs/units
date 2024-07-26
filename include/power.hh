#pragma once

#include <wither/units/energy.hh>
#include <wither/units/time.hh>

namespace units
{

using watts = impl::divide<joules, seconds>;

namespace dimensions
{

using energy = joules::magkind::dimension;

} // namespace dimensions

} // namespace units

