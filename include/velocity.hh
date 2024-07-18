#pragma once

#include <wither/units/length.hh>
#include <wither/units/time.hh>

namespace units
{

namespace kind
{

using metres_per_second = impl::divide_kinds<metres, seconds>;

using kilometres_per_hour = impl::divide_kinds<kilometres, hours>;
using miles_per_hour      = impl::divide_kinds<miles, hours>;
using inches_per_second   = impl::divide_kinds<inches, seconds>;
using feet_per_second     = impl::divide_kinds<feet, seconds>;
using knots               = impl::divide_kinds<nautical_miles, hours>;

} // namespace kind

using metres_per_second   = impl::magnitude<kind::metres_per_second, double>;
using kilometres_per_hour = impl::magnitude<kind::kilometres_per_hour, double>;
using miles_per_hour      = impl::magnitude<kind::miles_per_hour, double>;
using inches_per_second   = impl::magnitude<kind::inches_per_second, double>;
using feet_per_second     = impl::magnitude<kind::feet_per_second, double>;
using knots               = impl::magnitude<kind::knots, double>;

namespace dim
{

using velocity = kind::metres_per_second::dimension;

} // namespace dim

} // namespace units

