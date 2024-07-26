#pragma once

#include <wither/units/length.hh>

namespace units
{

using reciprocal_metres = impl::reciprocal<metres>;

namespace dimensions
{

using wavenumber = reciprocal_metres::magkind::dimension;

} // namespace dimensions

} // namespace units

