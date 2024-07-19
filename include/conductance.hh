#pragma once

#include <wither/units/resistance.hh>

namespace units
{

namespace kind
{

// clang-format off

using siemens      = impl::kind_reciprocal<ohms>;
using attosiemens  = impl::swap_kind_prefix<siemens, impl::prefix::atto>;
using femtosiemens = impl::swap_kind_prefix<siemens, impl::prefix::femto>;
using picosiemens  = impl::swap_kind_prefix<siemens, impl::prefix::pico>;
using nanosiemens  = impl::swap_kind_prefix<siemens, impl::prefix::nano>;
using microsiemens = impl::swap_kind_prefix<siemens, impl::prefix::micro>;
using millisiemens = impl::swap_kind_prefix<siemens, impl::prefix::milli>;
using centisiemens = impl::swap_kind_prefix<siemens, impl::prefix::centi>;
using decisiemens  = impl::swap_kind_prefix<siemens, impl::prefix::deci>;
using nonesiemens  = impl::swap_kind_prefix<siemens, impl::prefix::none>;
using decasiemens  = impl::swap_kind_prefix<siemens, impl::prefix::deca>;
using hectosiemens = impl::swap_kind_prefix<siemens, impl::prefix::hecto>;
using kilosiemens  = impl::swap_kind_prefix<siemens, impl::prefix::kilo>;
using megasiemens  = impl::swap_kind_prefix<siemens, impl::prefix::mega>;
using gigasiemens  = impl::swap_kind_prefix<siemens, impl::prefix::giga>;
using terasiemens  = impl::swap_kind_prefix<siemens, impl::prefix::tera>;
using petasiemens  = impl::swap_kind_prefix<siemens, impl::prefix::peta>;
using exasiemens   = impl::swap_kind_prefix<siemens, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using siemens      = impl::magnitude<kind::siemens, double>;
using attosiemens  = impl::magnitude<kind::attosiemens, double>;
using femtosiemens = impl::magnitude<kind::femtosiemens, double>;
using picosiemens  = impl::magnitude<kind::picosiemens, double>;
using nanosiemens  = impl::magnitude<kind::nanosiemens, double>;
using microsiemens = impl::magnitude<kind::microsiemens, double>;
using millisiemens = impl::magnitude<kind::millisiemens, double>;
using centisiemens = impl::magnitude<kind::centisiemens, double>;
using decisiemens  = impl::magnitude<kind::decisiemens, double>;
using nonesiemens  = impl::magnitude<kind::nonesiemens, double>;
using decasiemens  = impl::magnitude<kind::decasiemens, double>;
using hectosiemens = impl::magnitude<kind::hectosiemens, double>;
using kilosiemens  = impl::magnitude<kind::kilosiemens, double>;
using megasiemens  = impl::magnitude<kind::megasiemens, double>;
using gigasiemens  = impl::magnitude<kind::gigasiemens, double>;
using terasiemens  = impl::magnitude<kind::terasiemens, double>;
using petasiemens  = impl::magnitude<kind::petasiemens, double>;
using exasiemens   = impl::magnitude<kind::exasiemens, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

