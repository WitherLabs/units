#pragma once

#include <wither/units/velocity.hh>

namespace units
{

namespace kind
{

using metres_per_second_squared
    = impl::divide_kinds<metres_per_second, seconds>;

using kilometres_per_hour_squared
    = impl::divide_kinds<kilometres_per_hour, hours>;

using kilometres_per_hour_per_second
    = impl::divide_kinds<kilometres_per_hour, seconds>;

using feet_per_second_squared = impl::divide_kinds<feet_per_second, seconds>;

using inches_per_second_squared
    = impl::divide_kinds<inches_per_second, seconds>;

using knots_per_second = impl::divide_kinds<knots, seconds>;
using knots_per_hour   = impl::divide_kinds<knots, hours>;

} // namespace kind

using metres_per_second_squared
    = impl::magnitude<kind::metres_per_second_squared, double>;

using kilometres_per_hour_squared
    = impl::magnitude<kind::kilometres_per_hour_squared, double>;

using kilometres_per_hour_per_second
    = impl::magnitude<kind::kilometres_per_hour_per_second, double>;

using feet_per_second_squared
    = impl::magnitude<kind::feet_per_second_squared, double>;

using inches_per_second_squared
    = impl::magnitude<kind::inches_per_second_squared, double>;

using knots_per_second = impl::magnitude<kind::knots_per_second, double>;
using knots_per_hour   = impl::magnitude<kind::knots_per_hour, double>;

namespace dim
{
}

} // namespace units

