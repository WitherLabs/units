#pragma once

#include <wither/units/current.hh>
#include <wither/units/time.hh>

namespace units
{

using coulombs = impl::multiply<amperes, seconds>;

namespace dimensions
{

using charge = coulombs::magkind::dimension;

} // namespace dimensions

} // namespace units

