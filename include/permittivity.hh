#pragma once

#include <wither/units/capacitance.hh>

namespace units
{

using farads_per_metre = impl::divide<farads, metres>;

namespace dimensions
{

using permittivity = farads_per_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

