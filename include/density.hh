#pragma once

#include <wither/units/mass.hh>
#include <wither/units/volume.hh>

namespace units
{

using kilograms_per_cubic_metre = impl::divide<kilo<grams>, cubic_metres>;

namespace dimensions
{

using wavenumber = kilogram_per_cubic_metre::magkind::dimension;

} // namespace dimensions

} // namespace units

