#pragma once

#include <wither/units/length.hh>

namespace units
{

namespace kind
{

using metres_squared = impl::multiply_kinds<metres, metres>;

using attometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::atto>;
using femtometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::femto>;
using picometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::pico>;
using nanometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::nano>;
using micrometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::micro>;
using millimetres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::milli>;
using centimetres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::centi>;
using decimetres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::deci>;
using nonemetres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::none>;
using decametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::deca>;
using hectometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::hecto>;
using kilometres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::kilo>;
using megametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::mega>;
using gigametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::giga>;
using terametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::tera>;
using petametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::peta>;
using exametres_squared
    = impl::swap_kind_prefix<metres_squared, impl::prefix::exa>;

using feet_squared   = impl::multiply_kinds<feet, feet>;
using inches_squared = impl::multiply_kinds<inches, inches>;
using miles_squared  = impl::multiply_kinds<miles, miles>;

} // namespace kind

using metres_squared = impl::magnitude<kind::metres_squared, double>;

using attometres_squared  = impl::magnitude<kind::attometres_squared, double>;
using femtometres_squared = impl::magnitude<kind::femtometres_squared, double>;
using picometres_squared  = impl::magnitude<kind::picometres_squared, double>;
using nanometres_squared  = impl::magnitude<kind::nanometres_squared, double>;
using micrometres_squared = impl::magnitude<kind::micrometres_squared, double>;
using millimetres_squared = impl::magnitude<kind::millimetres_squared, double>;
using centimetres_squared = impl::magnitude<kind::centimetres_squared, double>;
using decimetres_squared  = impl::magnitude<kind::decimetres_squared, double>;
using nonemetres_squared  = impl::magnitude<kind::nonemetres_squared, double>;
using decametres_squared  = impl::magnitude<kind::decametres_squared, double>;
using hectometres_squared = impl::magnitude<kind::hectometres_squared, double>;
using kilometres_squared  = impl::magnitude<kind::kilometres_squared, double>;
using megametres_squared  = impl::magnitude<kind::megametres_squared, double>;
using gigametres_squared  = impl::magnitude<kind::gigametres_squared, double>;
using terametres_squared  = impl::magnitude<kind::terametres_squared, double>;
using petametres_squared  = impl::magnitude<kind::petametres_squared, double>;
using exametres_squared   = impl::magnitude<kind::exametres_squared, double>;

using feet_squared   = impl::magnitude<kind::feet_squared, double>;
using inches_squared = impl::magnitude<kind::inches_squared, double>;
using miles_squared  = impl::magnitude<kind::miles_squared, double>;

namespace dim
{
using area = kind::metres_squared::dimension;
} // namespace dim

} // namespace units

