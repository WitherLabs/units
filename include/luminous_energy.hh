#pragma once

#include <wither/units/luminous_flux.hh>
#include <wither/units/time.hh>

namespace units
{

using lumen_second = impl::multiply<lumens, seconds>;

namespace dimensions
{

using luminous_energy = lumen_second::magkind::dimension;

} // namespace dimensions

} // namespace units

