#pragma once

#include <wither/units/current.hh>
#include <wither/units/voltage.hh>

namespace units
{

using ohms = impl::divide<volts, amperes>;

namespace dimensions
{

using electrical_resistance = ohms::magkind::dimension;

} // namespace dimensions

} // namespace units

