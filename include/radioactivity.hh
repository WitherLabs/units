#pragma once

#include <wither/units/time.hh>

namespace units
{

using becquerels = impl::reciprocal<seconds>;

namespace dimensions
{

using radioactivity = becquerels::magkind::dimension;

} // namespace dimensions

} // namespace units

