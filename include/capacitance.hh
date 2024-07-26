#pragma once

#include <wither/units/charge.hh>
#include <wither/units/voltage.hh>

namespace units
{

using farads = impl::divide<coulombs, volts>;

namespace dimensions
{

using capacitance = farads::magkind::dimension;

} // namespace dimensions

} // namespace units

