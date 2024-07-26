#pragma once

#include <wither/units/energy.hh>
#include <wither/units/time.hh>

namespace units
{

using joule_seconds = impl::multiply<joules, seconds>;

namespace dimensions
{

using action = joule_seconds::magkind::dimension;

} // namespace dimensions

} // namespace units

