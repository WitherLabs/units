#pragma once

#include <wither/units/time.hh>
#include <wither/units/voltage.hh>

namespace units
{

using webers = impl::multiply<volts, seconds>;

namespace dimensions
{

using magnetic_flux = webers::magkind::dimension;

} // namespace dimensions

} // namespace units

