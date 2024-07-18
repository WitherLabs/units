#pragma once

#include <wither/units/length.hh>
#include <wither/units/time.hh>

namespace units
{

namespace kind
{

// clang-format off

using metres_per_second      = impl::divide_kinds<metres, seconds>;
using attometres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::atto>;
using femtometres_per_second = impl::swap_kind_prefix<metres_per_second, impl::prefix::femto>;
using picometres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::pico>;
using nanometres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::nano>;
using micrometres_per_second = impl::swap_kind_prefix<metres_per_second, impl::prefix::micro>;
using millimetres_per_second = impl::swap_kind_prefix<metres_per_second, impl::prefix::milli>;
using centimetres_per_second = impl::swap_kind_prefix<metres_per_second, impl::prefix::centi>;
using decimetres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::deci>;
using nonemetres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::none>;
using decametres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::deca>;
using hectometres_per_second = impl::swap_kind_prefix<metres_per_second, impl::prefix::hecto>;
using kilometres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::kilo>;
using megametres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::mega>;
using gigametres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::giga>;
using terametres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::tera>;
using petametres_per_second  = impl::swap_kind_prefix<metres_per_second, impl::prefix::peta>;
using exametres_per_second   = impl::swap_kind_prefix<metres_per_second, impl::prefix::exa>;

using metres_per_hour      = impl::divide_kinds<metres, hours>;
using attometres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::atto>;
using femtometres_per_hour = impl::swap_kind_prefix<metres_per_hour, impl::prefix::femto>;
using picometres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::pico>;
using nanometres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::nano>;
using micrometres_per_hour = impl::swap_kind_prefix<metres_per_hour, impl::prefix::micro>;
using millimetres_per_hour = impl::swap_kind_prefix<metres_per_hour, impl::prefix::milli>;
using centimetres_per_hour = impl::swap_kind_prefix<metres_per_hour, impl::prefix::centi>;
using decimetres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::deci>;
using nonemetres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::none>;
using decametres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::deca>;
using hectometres_per_hour = impl::swap_kind_prefix<metres_per_hour, impl::prefix::hecto>;
using kilometres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::kilo>;
using megametres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::mega>;
using gigametres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::giga>;
using terametres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::tera>;
using petametres_per_hour  = impl::swap_kind_prefix<metres_per_hour, impl::prefix::peta>;
using exametres_per_hour   = impl::swap_kind_prefix<metres_per_hour, impl::prefix::exa>;

using miles_per_hour    = impl::divide_kinds<miles, hours>;
using inches_per_second = impl::divide_kinds<inches, seconds>;
using feet_per_second   = impl::divide_kinds<feet, seconds>;
using knots             = impl::divide_kinds<nautical_miles, hours>;

// clang-format on

} // namespace kind

// clang-format off
//
using metres_per_second      = impl::magnitude<kind::metres_per_second, double>; //...
using attometres_per_second  = impl::magnitude<kind::attometres_per_second, double>; //...
using femtometres_per_second = impl::magnitude<kind::femtometres_per_second, double>; //...
using picometres_per_second  = impl::magnitude<kind::picometres_per_second, double>; //...
using nanometres_per_second  = impl::magnitude<kind::nanometres_per_second, double>; //...
using micrometres_per_second = impl::magnitude<kind::micrometres_per_second, double>; //...
using millimetres_per_second = impl::magnitude<kind::millimetres_per_second, double>; //...
using centimetres_per_second = impl::magnitude<kind::centimetres_per_second, double>; //...
using decimetres_per_second  = impl::magnitude<kind::decimetres_per_second, double>; //...
using nonemetres_per_second  = impl::magnitude<kind::nonemetres_per_second, double>; //...
using decametres_per_second  = impl::magnitude<kind::decametres_per_second, double>; //...
using hectometres_per_second = impl::magnitude<kind::hectometres_per_second, double>; //...
using kilometres_per_second  = impl::magnitude<kind::kilometres_per_second, double>; //...
using megametres_per_second  = impl::magnitude<kind::megametres_per_second, double>; //...
using gigametres_per_second  = impl::magnitude<kind::gigametres_per_second, double>; //...
using terametres_per_second  = impl::magnitude<kind::terametres_per_second, double>; //...
using petametres_per_second  = impl::magnitude<kind::petametres_per_second, double>; //...
using exametres_per_second   = impl::magnitude<kind::exametres_per_second, double>; //...

using metres_per_hour      = impl::magnitude<kind::metres_per_hour, double>; //...
using attometres_per_hour  = impl::magnitude<kind::attometres_per_hour, double>; //...
using femtometres_per_hour = impl::magnitude<kind::femtometres_per_hour, double>; //...
using picometres_per_hour  = impl::magnitude<kind::picometres_per_hour, double>; //...
using nanometres_per_hour  = impl::magnitude<kind::nanometres_per_hour, double>; //...
using micrometres_per_hour = impl::magnitude<kind::micrometres_per_hour, double>; //...
using millimetres_per_hour = impl::magnitude<kind::millimetres_per_hour, double>; //...
using centimetres_per_hour = impl::magnitude<kind::centimetres_per_hour, double>; //...
using decimetres_per_hour  = impl::magnitude<kind::decimetres_per_hour, double>; //...
using nonemetres_per_hour  = impl::magnitude<kind::nonemetres_per_hour, double>; //...
using decametres_per_hour  = impl::magnitude<kind::decametres_per_hour, double>; //...
using hectometres_per_hour = impl::magnitude<kind::hectometres_per_hour, double>; //...
using kilometres_per_hour  = impl::magnitude<kind::kilometres_per_hour, double>; //...
using megametres_per_hour  = impl::magnitude<kind::megametres_per_hour, double>; //...
using gigametres_per_hour  = impl::magnitude<kind::gigametres_per_hour, double>; //...
using terametres_per_hour  = impl::magnitude<kind::terametres_per_hour, double>; //...
using petametres_per_hour  = impl::magnitude<kind::petametres_per_hour, double>; //...
using exametres_per_hour   = impl::magnitude<kind::exametres_per_hour, double>; //...

using kilometres_per_hour = impl::magnitude<kind::kilometres_per_hour, double>;             //...
using miles_per_hour      = impl::magnitude<kind::miles_per_hour, double>; //...
using inches_per_second   = impl::magnitude<kind::inches_per_second, double>;                 //...
using feet_per_second     = impl::magnitude<kind::feet_per_second, double>; //...
using knots               = impl::magnitude<kind::knots, double>;           //...
                                                                        //
// clang-format on

namespace dim
{

using velocity = kind::metres_per_second::dimension;

} // namespace dim

} // namespace units

