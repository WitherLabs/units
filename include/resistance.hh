#pragma once

#include <wither/units/voltage.hh>

namespace units
{

namespace kind
{

// clang-format off

using ohms      = impl::divide_kinds<volts, amperes>;
using attoohms  = impl::swap_kind_prefix<ohms, impl::prefix::atto>;
using femtoohms = impl::swap_kind_prefix<ohms, impl::prefix::femto>;
using picoohms  = impl::swap_kind_prefix<ohms, impl::prefix::pico>;
using nanoohms  = impl::swap_kind_prefix<ohms, impl::prefix::nano>;
using microohms = impl::swap_kind_prefix<ohms, impl::prefix::micro>;
using milliohms = impl::swap_kind_prefix<ohms, impl::prefix::milli>;
using centiohms = impl::swap_kind_prefix<ohms, impl::prefix::centi>;
using deciohms  = impl::swap_kind_prefix<ohms, impl::prefix::deci>;
using noneohms  = impl::swap_kind_prefix<ohms, impl::prefix::none>;
using decaohms  = impl::swap_kind_prefix<ohms, impl::prefix::deca>;
using hectoohms = impl::swap_kind_prefix<ohms, impl::prefix::hecto>;
using kiloohms  = impl::swap_kind_prefix<ohms, impl::prefix::kilo>;
using megaohms  = impl::swap_kind_prefix<ohms, impl::prefix::mega>;
using gigaohms  = impl::swap_kind_prefix<ohms, impl::prefix::giga>;
using teraohms  = impl::swap_kind_prefix<ohms, impl::prefix::tera>;
using petaohms  = impl::swap_kind_prefix<ohms, impl::prefix::peta>;
using exaohms   = impl::swap_kind_prefix<ohms, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using ohms      = impl::magnitude<kind::ohms, double>;
using attoohms  = impl::magnitude<kind::attoohms, double>;
using femtoohms = impl::magnitude<kind::femtoohms, double>;
using picoohms  = impl::magnitude<kind::picoohms, double>;
using nanoohms  = impl::magnitude<kind::nanoohms, double>;
using microohms = impl::magnitude<kind::microohms, double>;
using milliohms = impl::magnitude<kind::milliohms, double>;
using centiohms = impl::magnitude<kind::centiohms, double>;
using deciohms  = impl::magnitude<kind::deciohms, double>;
using noneohms  = impl::magnitude<kind::noneohms, double>;
using decaohms  = impl::magnitude<kind::decaohms, double>;
using hectoohms = impl::magnitude<kind::hectoohms, double>;
using kiloohms  = impl::magnitude<kind::kiloohms, double>;
using megaohms  = impl::magnitude<kind::megaohms, double>;
using gigaohms  = impl::magnitude<kind::gigaohms, double>;
using teraohms  = impl::magnitude<kind::teraohms, double>;
using petaohms  = impl::magnitude<kind::petaohms, double>;
using exaohms   = impl::magnitude<kind::exaohms, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

