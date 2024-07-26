#pragma once

#include <wither/units/area.hh>
#include <wither/units/current.hh>

namespace units
{

using amperes_per_square_metre = impl::divide<amperes, square_metres>;

namespace dimensions
{

using current_density = amperes_per_square_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

