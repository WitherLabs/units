#pragma once

#include <wither/units/units.hh>

namespace units
{

using unit = impl::basic<impl::no_dimension, long double>;

namespace dimensions
{

using dim = unit::magkind::dimension;

} // namespace dimensions

} // namespace units

