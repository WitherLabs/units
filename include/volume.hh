#pragma once

#include <wither/units/area.hh>

namespace units
{

using cubic_metres = impl::cubic<metres>;

namespace dimensions
{

using volume = cubic_metres::magkind::dimension;

} // namespace dimensions

} // namespace units

