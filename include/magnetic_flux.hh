#pragma once

#include <wither/units/voltage.hh>

namespace units
{

namespace kind
{

// clang-format off

using webers      = impl::multiply_kinds<volts, seconds>;
using attowebers  = impl::swap_kind_prefix<webers, impl::prefix::atto>;
using femtowebers = impl::swap_kind_prefix<webers, impl::prefix::femto>;
using picowebers  = impl::swap_kind_prefix<webers, impl::prefix::pico>;
using nanowebers  = impl::swap_kind_prefix<webers, impl::prefix::nano>;
using microwebers = impl::swap_kind_prefix<webers, impl::prefix::micro>;
using milliwebers = impl::swap_kind_prefix<webers, impl::prefix::milli>;
using centiwebers = impl::swap_kind_prefix<webers, impl::prefix::centi>;
using deciwebers  = impl::swap_kind_prefix<webers, impl::prefix::deci>;
using nonewebers  = impl::swap_kind_prefix<webers, impl::prefix::none>;
using decawebers  = impl::swap_kind_prefix<webers, impl::prefix::deca>;
using hectowebers = impl::swap_kind_prefix<webers, impl::prefix::hecto>;
using kilowebers  = impl::swap_kind_prefix<webers, impl::prefix::kilo>;
using megawebers  = impl::swap_kind_prefix<webers, impl::prefix::mega>;
using gigawebers  = impl::swap_kind_prefix<webers, impl::prefix::giga>;
using terawebers  = impl::swap_kind_prefix<webers, impl::prefix::tera>;
using petawebers  = impl::swap_kind_prefix<webers, impl::prefix::peta>;
using exawebers   = impl::swap_kind_prefix<webers, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using webers      = impl::magnitude<kind::webers, double>;
using attowebers  = impl::magnitude<kind::attowebers, double>;
using femtowebers = impl::magnitude<kind::femtowebers, double>;
using picowebers  = impl::magnitude<kind::picowebers, double>;
using nanowebers  = impl::magnitude<kind::nanowebers, double>;
using microwebers = impl::magnitude<kind::microwebers, double>;
using milliwebers = impl::magnitude<kind::milliwebers, double>;
using centiwebers = impl::magnitude<kind::centiwebers, double>;
using deciwebers  = impl::magnitude<kind::deciwebers, double>;
using nonewebers  = impl::magnitude<kind::nonewebers, double>;
using decawebers  = impl::magnitude<kind::decawebers, double>;
using hectowebers = impl::magnitude<kind::hectowebers, double>;
using kilowebers  = impl::magnitude<kind::kilowebers, double>;
using megawebers  = impl::magnitude<kind::megawebers, double>;
using gigawebers  = impl::magnitude<kind::gigawebers, double>;
using terawebers  = impl::magnitude<kind::terawebers, double>;
using petawebers  = impl::magnitude<kind::petawebers, double>;
using exawebers   = impl::magnitude<kind::exawebers, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

