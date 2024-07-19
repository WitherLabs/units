#pragma once

#include <wither/units/charge.hh>
#include <wither/units/energy.hh>

namespace units
{

namespace kind
{

// clang-format off

using volts      = impl::divide_kinds<joules, coulombs>;
using attovolts  = impl::swap_kind_prefix<volts, impl::prefix::atto>;
using femtovolts = impl::swap_kind_prefix<volts, impl::prefix::femto>;
using picovolts  = impl::swap_kind_prefix<volts, impl::prefix::pico>;
using nanovolts  = impl::swap_kind_prefix<volts, impl::prefix::nano>;
using microvolts = impl::swap_kind_prefix<volts, impl::prefix::micro>;
using millivolts = impl::swap_kind_prefix<volts, impl::prefix::milli>;
using centivolts = impl::swap_kind_prefix<volts, impl::prefix::centi>;
using decivolts  = impl::swap_kind_prefix<volts, impl::prefix::deci>;
using nonevolts  = impl::swap_kind_prefix<volts, impl::prefix::none>;
using decavolts  = impl::swap_kind_prefix<volts, impl::prefix::deca>;
using hectovolts = impl::swap_kind_prefix<volts, impl::prefix::hecto>;
using kilovolts  = impl::swap_kind_prefix<volts, impl::prefix::kilo>;
using megavolts  = impl::swap_kind_prefix<volts, impl::prefix::mega>;
using gigavolts  = impl::swap_kind_prefix<volts, impl::prefix::giga>;
using teravolts  = impl::swap_kind_prefix<volts, impl::prefix::tera>;
using petavolts  = impl::swap_kind_prefix<volts, impl::prefix::peta>;
using exavolts   = impl::swap_kind_prefix<volts, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using volts      = impl::magnitude<kind::volts, double>;
using attovolts  = impl::magnitude<kind::attovolts, double>;
using femtovolts = impl::magnitude<kind::femtovolts, double>;
using picovolts  = impl::magnitude<kind::picovolts, double>;
using nanovolts  = impl::magnitude<kind::nanovolts, double>;
using microvolts = impl::magnitude<kind::microvolts, double>;
using millivolts = impl::magnitude<kind::millivolts, double>;
using centivolts = impl::magnitude<kind::centivolts, double>;
using decivolts  = impl::magnitude<kind::decivolts, double>;
using nonevolts  = impl::magnitude<kind::nonevolts, double>;
using decavolts  = impl::magnitude<kind::decavolts, double>;
using hectovolts = impl::magnitude<kind::hectovolts, double>;
using kilovolts  = impl::magnitude<kind::kilovolts, double>;
using megavolts  = impl::magnitude<kind::megavolts, double>;
using gigavolts  = impl::magnitude<kind::gigavolts, double>;
using teravolts  = impl::magnitude<kind::teravolts, double>;
using petavolts  = impl::magnitude<kind::petavolts, double>;
using exavolts   = impl::magnitude<kind::exavolts, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

