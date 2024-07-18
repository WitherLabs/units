#pragma once

#include <wither/units/area.hh>

namespace units
{

namespace kind
{

using metres_cubed = impl::multiply_kinds<metres_squared, metres>;

using attometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::atto>;
using femtometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::femto>;
using picometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::pico>;
using nanometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::nano>;
using micrometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::micro>;
using millimetres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::milli>;
using centimetres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::centi>;
using decimetres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::deci>;
using nonemetres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::none>;
using decametres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::deca>;
using hectometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::hecto>;
using kilometres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::kilo>;
using megametres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::mega>;
using gigametres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::giga>;
using terametres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::tera>;
using petametres_cubed
    = impl::swap_kind_prefix<metres_cubed, impl::prefix::peta>;
using exametres_cubed = impl::swap_kind_prefix<metres_cubed, impl::prefix::exa>;

using feet_cubed   = impl::multiply_kinds<feet_squared, feet>;
using inches_cubed = impl::multiply_kinds<inches_squared, inches>;
using miles_cubed  = impl::multiply_kinds<miles_squared, miles>;

} // namespace kind

using metres_cubed = impl::magnitude<kind::metres_cubed, double>;

using attometres_cubed  = impl::magnitude<kind::attometres_cubed, double>;
using femtometres_cubed = impl::magnitude<kind::femtometres_cubed, double>;
using picometres_cubed  = impl::magnitude<kind::picometres_cubed, double>;
using nanometres_cubed  = impl::magnitude<kind::nanometres_cubed, double>;
using micrometres_cubed = impl::magnitude<kind::micrometres_cubed, double>;
using millimetres_cubed = impl::magnitude<kind::millimetres_cubed, double>;
using centimetres_cubed = impl::magnitude<kind::centimetres_cubed, double>;
using decimetres_cubed  = impl::magnitude<kind::decimetres_cubed, double>;
using nonemetres_cubed  = impl::magnitude<kind::nonemetres_cubed, double>;
using decametres_cubed  = impl::magnitude<kind::decametres_cubed, double>;
using hectometres_cubed = impl::magnitude<kind::hectometres_cubed, double>;
using kilometres_cubed  = impl::magnitude<kind::kilometres_cubed, double>;
using megametres_cubed  = impl::magnitude<kind::megametres_cubed, double>;
using gigametres_cubed  = impl::magnitude<kind::gigametres_cubed, double>;
using terametres_cubed  = impl::magnitude<kind::terametres_cubed, double>;
using petametres_cubed  = impl::magnitude<kind::petametres_cubed, double>;
using exametres_cubed   = impl::magnitude<kind::exametres_cubed, double>;

using feet_cubed   = impl::magnitude<kind::feet_cubed, double>;
using inches_cubed = impl::magnitude<kind::inches_cubed, double>;
using miles_cubed  = impl::magnitude<kind::miles_cubed, double>;

namespace dim
{
using volume = kind::metres_cubed::dimension;
} // namespace dim

} // namespace units

