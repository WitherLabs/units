#pragma once

#include <wither/units/energy.hh>
#include <wither/units/time.hh>

namespace units
{

using watts = impl::divide<joules, seconds>;

namespace dimensions
{

using power = watts::magkind::dimension;

} // namespace dimensions

} // namespace units

