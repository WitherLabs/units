#pragma once

#include <wither/units/dose.hh>

namespace units
{

using grays_per_second = impl::divide<grays, seconds>;

namespace dimensions
{

using absorbed_dose_rate = grays_per_second::magkind::dimension;

} // namespace dimensions

} // namespace units

