#pragma once

#include <wither/units/substance.hh>
#include <wither/units/time.hh>

namespace units
{

using katals = impl::divide<moles, seconds>;

namespace dimensions
{

using catalytic_activity = katals::magkind::dimension;

} // namespace dimensions

} // namespace units

