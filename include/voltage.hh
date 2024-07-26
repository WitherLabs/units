#pragma once

#include <wither/units/charge.hh>
#include <wither/units/energy.hh>

namespace units
{

using volts = impl::divide<joules, coulombs>;

namespace dimensions
{

using voltage = volts::magkind::dimension;

} // namespace dimensions

} // namespace units

