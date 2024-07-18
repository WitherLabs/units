#pragma once

#include <wither/units/time.hh>

namespace units
{

namespace kind
{

using hertz      = impl::kind_reciprocal<seconds>;
using attohertz  = impl::swap_kind_prefix<hertz, impl::prefix::atto>;
using femtohertz = impl::swap_kind_prefix<hertz, impl::prefix::femto>;
using picohertz  = impl::swap_kind_prefix<hertz, impl::prefix::pico>;
using nanohertz  = impl::swap_kind_prefix<hertz, impl::prefix::nano>;
using microhertz = impl::swap_kind_prefix<hertz, impl::prefix::micro>;
using millihertz = impl::swap_kind_prefix<hertz, impl::prefix::milli>;
using centihertz = impl::swap_kind_prefix<hertz, impl::prefix::centi>;
using decihertz  = impl::swap_kind_prefix<hertz, impl::prefix::deci>;
using nonehertz  = impl::swap_kind_prefix<hertz, impl::prefix::none>;
using decahertz  = impl::swap_kind_prefix<hertz, impl::prefix::deca>;
using hectohertz = impl::swap_kind_prefix<hertz, impl::prefix::hecto>;
using kilohertz  = impl::swap_kind_prefix<hertz, impl::prefix::kilo>;
using megahertz  = impl::swap_kind_prefix<hertz, impl::prefix::mega>;
using gigahertz  = impl::swap_kind_prefix<hertz, impl::prefix::giga>;
using terahertz  = impl::swap_kind_prefix<hertz, impl::prefix::tera>;
using petahertz  = impl::swap_kind_prefix<hertz, impl::prefix::peta>;
using exahertz   = impl::swap_kind_prefix<hertz, impl::prefix::exa>;

} // namespace kind

using hertz      = impl::magnitude<kind::hertz, double>;
using attohertz  = impl::magnitude<kind::attohertz, double>;
using femtohertz = impl::magnitude<kind::femtohertz, double>;
using picohertz  = impl::magnitude<kind::picohertz, double>;
using nanohertz  = impl::magnitude<kind::nanohertz, double>;
using microhertz = impl::magnitude<kind::microhertz, double>;
using millihertz = impl::magnitude<kind::millihertz, double>;
using centihertz = impl::magnitude<kind::centihertz, double>;
using decihertz  = impl::magnitude<kind::decihertz, double>;
using nonehertz  = impl::magnitude<kind::nonehertz, double>;
using decahertz  = impl::magnitude<kind::decahertz, double>;
using hectohertz = impl::magnitude<kind::hectohertz, double>;
using kilohertz  = impl::magnitude<kind::kilohertz, double>;
using megahertz  = impl::magnitude<kind::megahertz, double>;
using gigahertz  = impl::magnitude<kind::gigahertz, double>;
using terahertz  = impl::magnitude<kind::terahertz, double>;
using petahertz  = impl::magnitude<kind::petahertz, double>;
using exahertz   = impl::magnitude<kind::exahertz, double>;

namespace dim
{

using frequency = kind::hertz::dimension;

} // namespace dim

} // namespace units

