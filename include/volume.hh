#pragma once

#include <wither/units/area.hh>

namespace units
{

using cubed_metres = impl::cube<metres>;

namespace dimensions
{

using volume = cubed_metres::magkind::dimension;

} // namespace dimensions

} // namespace units

