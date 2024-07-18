#pragma once

#include <wither/units/time.hh>

namespace units
{

namespace kind
{

using hertz = impl::kind_reciprocal<seconds>;

} // namespace kind

using hertz = impl::magnitude<kind::hertz, double>;

namespace dim
{

using frequency = kind::hertz::dimension;

} // namespace dim

} // namespace units

