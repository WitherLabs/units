#pragma once

#include <wither/units/inductance.hh>
#include <wither/units/length.hh>

namespace units
{

using henries_per_metre = impl::divide<henries, metres>;

namespace dimensions
{

using permeability = henries_per_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

