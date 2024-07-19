#pragma once

#include <wither/units/frequency.hh>
#include <wither/units/substance.hh>

namespace units
{

namespace kind
{

// clang-format off

using katals      = impl::multiply_kinds<moles, hertz>;
using attokatals  = impl::swap_kind_prefix<katals, impl::prefix::atto>;
using femtokatals = impl::swap_kind_prefix<katals, impl::prefix::femto>;
using picokatals  = impl::swap_kind_prefix<katals, impl::prefix::pico>;
using nanokatals  = impl::swap_kind_prefix<katals, impl::prefix::nano>;
using microkatals = impl::swap_kind_prefix<katals, impl::prefix::micro>;
using millikatals = impl::swap_kind_prefix<katals, impl::prefix::milli>;
using centikatals = impl::swap_kind_prefix<katals, impl::prefix::centi>;
using decikatals  = impl::swap_kind_prefix<katals, impl::prefix::deci>;
using nonekatals  = impl::swap_kind_prefix<katals, impl::prefix::none>;
using decakatals  = impl::swap_kind_prefix<katals, impl::prefix::deca>;
using hectokatals = impl::swap_kind_prefix<katals, impl::prefix::hecto>;
using kilokatals  = impl::swap_kind_prefix<katals, impl::prefix::kilo>;
using megakatals  = impl::swap_kind_prefix<katals, impl::prefix::mega>;
using gigakatals  = impl::swap_kind_prefix<katals, impl::prefix::giga>;
using terakatals  = impl::swap_kind_prefix<katals, impl::prefix::tera>;
using petakatals  = impl::swap_kind_prefix<katals, impl::prefix::peta>;
using exakatals   = impl::swap_kind_prefix<katals, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using katals      = impl::magnitude<kind::katals, double>;
using attokatals  = impl::magnitude<kind::attokatals, double>;
using femtokatals = impl::magnitude<kind::femtokatals, double>;
using picokatals  = impl::magnitude<kind::picokatals, double>;
using nanokatals  = impl::magnitude<kind::nanokatals, double>;
using microkatals = impl::magnitude<kind::microkatals, double>;
using millikatals = impl::magnitude<kind::millikatals, double>;
using centikatals = impl::magnitude<kind::centikatals, double>;
using decikatals  = impl::magnitude<kind::decikatals, double>;
using nonekatals  = impl::magnitude<kind::nonekatals, double>;
using decakatals  = impl::magnitude<kind::decakatals, double>;
using hectokatals = impl::magnitude<kind::hectokatals, double>;
using kilokatals  = impl::magnitude<kind::kilokatals, double>;
using megakatals  = impl::magnitude<kind::megakatals, double>;
using gigakatals  = impl::magnitude<kind::gigakatals, double>;
using terakatals  = impl::magnitude<kind::terakatals, double>;
using petakatals  = impl::magnitude<kind::petakatals, double>;
using exakatals   = impl::magnitude<kind::exakatals, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

