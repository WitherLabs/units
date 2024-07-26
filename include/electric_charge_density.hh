#pragma once

#include <wither/units/charge.hh>
#include <wither/units/volume.hh>

namespace units
{

using coulombs_per_cubic_metre = impl::divide<coulombs, cubic_metres>;

namespace dimensions
{

using electric_charge_density = coulombs_per_cubic_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

