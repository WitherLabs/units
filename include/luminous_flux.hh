#pragma once

#include <wither/units/luminous_intensity.hh>
#include <wither/units/solid_angle.hh>

namespace units
{

using lumens = impl::multiply<candelas, steradians>;

namespace dimensions
{

using luminous_flux = lumens::magkind::dimension;

} // namespace dimensions

} // namespace units

