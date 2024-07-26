#pragma once

#include <wither/units/current.hh>
#include <wither/units/length.hh>

namespace units
{

using amperes_per_metre = impl::divide<amperes, metres>;

namespace dimensions
{

using magnetic_field_strength = amperes_per_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

