#pragma once

#include <wither/units/force.hh>
#include <wither/units/length.hh>

namespace units
{

using newtons_per_metre = impl::divide<newtons, metres>;

namespace dimensions
{

using surface_tension = newtons_per_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

