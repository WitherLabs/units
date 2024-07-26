#pragma once

#include <wither/units/charge.hh>
#include <wither/units/mass.hh>

namespace units
{

using coulombs_per_kilogram = impl::divide<coulombs, kilo<grams>>;

namespace dimensions
{

using exposure = coulombs_per_kilogram::magkind::dimension;

} // namespace dimensions

} // namespace units

