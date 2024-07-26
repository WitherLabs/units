#pragma once

#include <wither/units/mass.hh>
#include <wither/units/velocity.hh>

namespace units
{

using kilogram_metres_per_second
    = impl::multiply<kilo<grams>, metres_per_second>;

namespace dimensions
{

using momentum = kilogram_metres_per_second::magkind::dimension;

} // namespace dimensions

} // namespace units

