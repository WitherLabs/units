#pragma once

#include <wither/units/velocity.hh>

namespace units
{

namespace kind
{

// clang-format off

using metres_per_second_squared      = impl::divide_kinds<metres_per_second, seconds>;
using attometres_per_second_squared  = impl::divide_kinds<attometres_per_second, seconds>;
using femtometres_per_second_squared = impl::divide_kinds<femtometres_per_second, seconds>;
using picometres_per_second_squared  = impl::divide_kinds<picometres_per_second, seconds>;
using nanometres_per_second_squared  = impl::divide_kinds<nanometres_per_second, seconds>;
using micrometres_per_second_squared = impl::divide_kinds<micrometres_per_second, seconds>;
using millimetres_per_second_squared = impl::divide_kinds<millimetres_per_second, seconds>;
using centimetres_per_second_squared = impl::divide_kinds<centimetres_per_second, seconds>;
using decimetres_per_second_squared  = impl::divide_kinds<decimetres_per_second, seconds>;
using nonemetres_per_second_squared  = impl::divide_kinds<nonemetres_per_second, seconds>;
using decametres_per_second_squared  = impl::divide_kinds<decametres_per_second, seconds>;
using hectometres_per_second_squared = impl::divide_kinds<hectometres_per_second, seconds>;
using kilometres_per_second_squared  = impl::divide_kinds<kilometres_per_second, seconds>;
using megametres_per_second_squared  = impl::divide_kinds<megametres_per_second, seconds>;
using gigametres_per_second_squared  = impl::divide_kinds<gigametres_per_second, seconds>;
using terametres_per_second_squared  = impl::divide_kinds<terametres_per_second, seconds>;
using petametres_per_second_squared  = impl::divide_kinds<petametres_per_second, seconds>;
using exametres_per_second_squared   = impl::divide_kinds<exametres_per_second, seconds>;

using metres_per_hour_squared      = impl::divide_kinds<metres_per_hour, hours>;
using attometres_per_hour_squared  = impl::divide_kinds<attometres_per_hour, hours>;
using femtometres_per_hour_squared = impl::divide_kinds<femtometres_per_hour, hours>;
using picometres_per_hour_squared  = impl::divide_kinds<picometres_per_hour, hours>;
using nanometres_per_hour_squared  = impl::divide_kinds<nanometres_per_hour, hours>;
using micrometres_per_hour_squared = impl::divide_kinds<micrometres_per_hour, hours>;
using millimetres_per_hour_squared = impl::divide_kinds<millimetres_per_hour, hours>;
using centimetres_per_hour_squared = impl::divide_kinds<centimetres_per_hour, hours>;
using decimetres_per_hour_squared  = impl::divide_kinds<decimetres_per_hour, hours>;
using nonemetres_per_hour_squared  = impl::divide_kinds<nonemetres_per_hour, hours>;
using decametres_per_hour_squared  = impl::divide_kinds<decametres_per_hour, hours>;
using hectometres_per_hour_squared = impl::divide_kinds<hectometres_per_hour, hours>;
using kilometres_per_hour_squared  = impl::divide_kinds<kilometres_per_hour, hours>;
using megametres_per_hour_squared  = impl::divide_kinds<megametres_per_hour, hours>;
using gigametres_per_hour_squared  = impl::divide_kinds<gigametres_per_hour, hours>;
using terametres_per_hour_squared  = impl::divide_kinds<terametres_per_hour, hours>;
using petametres_per_hour_squared  = impl::divide_kinds<petametres_per_hour, hours>;
using exametres_per_hour_squared   = impl::divide_kinds<exametres_per_hour, hours>;

using metres_per_hour_per_second      = impl::divide_kinds<metres_per_hour, seconds>;
using attometres_per_hour_per_second  = impl::divide_kinds<attometres_per_hour, seconds>;
using femtometres_per_hour_per_second = impl::divide_kinds<femtometres_per_hour, seconds>;
using picometres_per_hour_per_second  = impl::divide_kinds<picometres_per_hour, seconds>;
using nanometres_per_hour_per_second  = impl::divide_kinds<nanometres_per_hour, seconds>;
using micrometres_per_hour_per_second = impl::divide_kinds<micrometres_per_hour, seconds>;
using millimetres_per_hour_per_second = impl::divide_kinds<millimetres_per_hour, seconds>;
using centimetres_per_hour_per_second = impl::divide_kinds<centimetres_per_hour, seconds>;
using decimetres_per_hour_per_second  = impl::divide_kinds<decimetres_per_hour, seconds>;
using nonemetres_per_hour_per_second  = impl::divide_kinds<nonemetres_per_hour, seconds>;
using decametres_per_hour_per_second  = impl::divide_kinds<decametres_per_hour, seconds>;
using hectometres_per_hour_per_second = impl::divide_kinds<hectometres_per_hour, seconds>;
using kilometres_per_hour_per_second  = impl::divide_kinds<kilometres_per_hour, seconds>;
using megametres_per_hour_per_second  = impl::divide_kinds<megametres_per_hour, seconds>;
using gigametres_per_hour_per_second  = impl::divide_kinds<gigametres_per_hour, seconds>;
using terametres_per_hour_per_second  = impl::divide_kinds<terametres_per_hour, seconds>;
using petametres_per_hour_per_second  = impl::divide_kinds<petametres_per_hour, seconds>;
using exametres_per_hour_per_second   = impl::divide_kinds<exametres_per_hour, seconds>;

using feet_per_second_squared   = impl::divide_kinds<feet_per_second, seconds>;
using inches_per_second_squared = impl::divide_kinds<inches_per_second, seconds>;
using knots_per_second          = impl::divide_kinds<knots, seconds>;
using knots_per_hour            = impl::divide_kinds<knots, hours>;

// clang-format on

} // namespace kind

// clang-format off

using metres_per_second_squared      = impl::magnitude<kind::metres_per_second_squared, double>;
using attometres_per_second_squared  = impl::magnitude<kind::attometres_per_second_squared, double>;
using femtometres_per_second_squared = impl::magnitude<kind::femtometres_per_second_squared, double>;
using picometres_per_second_squared  = impl::magnitude<kind::picometres_per_second_squared, double>;
using nanometres_per_second_squared  = impl::magnitude<kind::nanometres_per_second_squared, double>;
using micrometres_per_second_squared = impl::magnitude<kind::micrometres_per_second_squared, double>;
using millimetres_per_second_squared = impl::magnitude<kind::millimetres_per_second_squared, double>;
using centimetres_per_second_squared = impl::magnitude<kind::centimetres_per_second_squared, double>;
using decimetres_per_second_squared  = impl::magnitude<kind::decimetres_per_second_squared, double>;
using nonemetres_per_second_squared  = impl::magnitude<kind::nonemetres_per_second_squared, double>;
using decametres_per_second_squared  = impl::magnitude<kind::decametres_per_second_squared, double>;
using hectometres_per_second_squared = impl::magnitude<kind::hectometres_per_second_squared, double>;
using kilometres_per_second_squared  = impl::magnitude<kind::kilometres_per_second_squared, double>;
using megametres_per_second_squared  = impl::magnitude<kind::megametres_per_second_squared, double>;
using gigametres_per_second_squared  = impl::magnitude<kind::gigametres_per_second_squared, double>;
using terametres_per_second_squared  = impl::magnitude<kind::terametres_per_second_squared, double>;
using petametres_per_second_squared  = impl::magnitude<kind::petametres_per_second_squared, double>;
using exametres_per_second_squared   = impl::magnitude<kind::exametres_per_second_squared, double>;

using metres_per_hour_squared      = impl::magnitude<kind::metres_per_hour_squared, double>;
using attometres_per_hour_squared  = impl::magnitude<kind::attometres_per_hour_squared, double>;
using femtometres_per_hour_squared = impl::magnitude<kind::femtometres_per_hour_squared, double>;
using picometres_per_hour_squared  = impl::magnitude<kind::picometres_per_hour_squared, double>;
using nanometres_per_hour_squared  = impl::magnitude<kind::nanometres_per_hour_squared, double>;
using micrometres_per_hour_squared = impl::magnitude<kind::micrometres_per_hour_squared, double>;
using millimetres_per_hour_squared = impl::magnitude<kind::millimetres_per_hour_squared, double>;
using centimetres_per_hour_squared = impl::magnitude<kind::centimetres_per_hour_squared, double>;
using decimetres_per_hour_squared  = impl::magnitude<kind::decimetres_per_hour_squared, double>;
using nonemetres_per_hour_squared  = impl::magnitude<kind::nonemetres_per_hour_squared, double>;
using decametres_per_hour_squared  = impl::magnitude<kind::decametres_per_hour_squared, double>;
using hectometres_per_hour_squared = impl::magnitude<kind::hectometres_per_hour_squared, double>;
using kilometres_per_hour_squared  = impl::magnitude<kind::kilometres_per_hour_squared, double>;
using megametres_per_hour_squared  = impl::magnitude<kind::megametres_per_hour_squared, double>;
using gigametres_per_hour_squared  = impl::magnitude<kind::gigametres_per_hour_squared, double>;
using terametres_per_hour_squared  = impl::magnitude<kind::terametres_per_hour_squared, double>;
using petametres_per_hour_squared  = impl::magnitude<kind::petametres_per_hour_squared, double>;
using exametres_per_hour_squared   = impl::magnitude<kind::exametres_per_hour_squared, double>;

using metres_per_hour_per_second      = impl::magnitude<kind::metres_per_hour_per_second, double>;
using attometres_per_hour_per_second  = impl::magnitude<kind::attometres_per_hour_per_second, double>;
using femtometres_per_hour_per_second = impl::magnitude<kind::femtometres_per_hour_per_second, double>;
using picometres_per_hour_per_second  = impl::magnitude<kind::picometres_per_hour_per_second, double>;
using nanometres_per_hour_per_second  = impl::magnitude<kind::nanometres_per_hour_per_second, double>;
using micrometres_per_hour_per_second = impl::magnitude<kind::micrometres_per_hour_per_second, double>;
using millimetres_per_hour_per_second = impl::magnitude<kind::millimetres_per_hour_per_second, double>;
using centimetres_per_hour_per_second = impl::magnitude<kind::centimetres_per_hour_per_second, double>;
using decimetres_per_hour_per_second  = impl::magnitude<kind::decimetres_per_hour_per_second, double>;
using nonemetres_per_hour_per_second  = impl::magnitude<kind::nonemetres_per_hour_per_second, double>;
using decametres_per_hour_per_second  = impl::magnitude<kind::decametres_per_hour_per_second, double>;
using hectometres_per_hour_per_second = impl::magnitude<kind::hectometres_per_hour_per_second, double>;
using kilometres_per_hour_per_second  = impl::magnitude<kind::kilometres_per_hour_per_second, double>;
using megametres_per_hour_per_second  = impl::magnitude<kind::megametres_per_hour_per_second, double>;
using gigametres_per_hour_per_second  = impl::magnitude<kind::gigametres_per_hour_per_second, double>;
using terametres_per_hour_per_second  = impl::magnitude<kind::terametres_per_hour_per_second, double>;
using petametres_per_hour_per_second  = impl::magnitude<kind::petametres_per_hour_per_second, double>;
using exametres_per_hour_per_second   = impl::magnitude<kind::exametres_per_hour_per_second, double>;

using feet_per_second_squared   = impl::magnitude<kind::feet_per_second_squared, double>;
using inches_per_second_squared = impl::magnitude<kind::inches_per_second_squared, double>;
using knots_per_second          = impl::magnitude<kind::knots_per_second, double>;
using knots_per_hour            = impl::magnitude<kind::knots_per_hour, double>;

// clang-format on

namespace dim
{
}

} // namespace units

