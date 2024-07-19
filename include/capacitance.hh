#pragma once

#include <wither/units/voltage.hh>

namespace units
{

namespace kind
{

// clang-format off

using farads      = impl::divide_kinds<coulombs, volts>;
using attofarads  = impl::swap_kind_prefix<farads, impl::prefix::atto>;
using femtofarads = impl::swap_kind_prefix<farads, impl::prefix::femto>;
using picofarads  = impl::swap_kind_prefix<farads, impl::prefix::pico>;
using nanofarads  = impl::swap_kind_prefix<farads, impl::prefix::nano>;
using microfarads = impl::swap_kind_prefix<farads, impl::prefix::micro>;
using millifarads = impl::swap_kind_prefix<farads, impl::prefix::milli>;
using centifarads = impl::swap_kind_prefix<farads, impl::prefix::centi>;
using decifarads  = impl::swap_kind_prefix<farads, impl::prefix::deci>;
using nonefarads  = impl::swap_kind_prefix<farads, impl::prefix::none>;
using decafarads  = impl::swap_kind_prefix<farads, impl::prefix::deca>;
using hectofarads = impl::swap_kind_prefix<farads, impl::prefix::hecto>;
using kilofarads  = impl::swap_kind_prefix<farads, impl::prefix::kilo>;
using megafarads  = impl::swap_kind_prefix<farads, impl::prefix::mega>;
using gigafarads  = impl::swap_kind_prefix<farads, impl::prefix::giga>;
using terafarads  = impl::swap_kind_prefix<farads, impl::prefix::tera>;
using petafarads  = impl::swap_kind_prefix<farads, impl::prefix::peta>;
using exafarads   = impl::swap_kind_prefix<farads, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using farads      = impl::magnitude<kind::farads, double>;
using attofarads  = impl::magnitude<kind::attofarads, double>;
using femtofarads = impl::magnitude<kind::femtofarads, double>;
using picofarads  = impl::magnitude<kind::picofarads, double>;
using nanofarads  = impl::magnitude<kind::nanofarads, double>;
using microfarads = impl::magnitude<kind::microfarads, double>;
using millifarads = impl::magnitude<kind::millifarads, double>;
using centifarads = impl::magnitude<kind::centifarads, double>;
using decifarads  = impl::magnitude<kind::decifarads, double>;
using nonefarads  = impl::magnitude<kind::nonefarads, double>;
using decafarads  = impl::magnitude<kind::decafarads, double>;
using hectofarads = impl::magnitude<kind::hectofarads, double>;
using kilofarads  = impl::magnitude<kind::kilofarads, double>;
using megafarads  = impl::magnitude<kind::megafarads, double>;
using gigafarads  = impl::magnitude<kind::gigafarads, double>;
using terafarads  = impl::magnitude<kind::terafarads, double>;
using petafarads  = impl::magnitude<kind::petafarads, double>;
using exafarads   = impl::magnitude<kind::exafarads, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

