#pragma once

#include <wither/units/force.hh>
#include <wither/units/length.hh>

namespace units
{

using netwon_metres = impl::multiply<newtons, metres>;

namespace dimensions
{

using torque = netwon_metres::magkind::dimension;

} // namespace dimensions

} // namespace units

