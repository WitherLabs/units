#pragma once

#include <wither/units/voltage.hh>

namespace units
{

using volt_per_metre = impl::divide<volts, metres>;

namespace dimensions
{

using electric_field_strength = volt_per_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

