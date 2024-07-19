#pragma once

#include <wither/units/magnetic_flux.hh>

namespace units
{

namespace kind
{

// clang-format off

using henrys      = impl::divide_kinds<webers, amperes>;
using attohenrys  = impl::swap_kind_prefix<henrys, impl::prefix::atto>;
using femtohenrys = impl::swap_kind_prefix<henrys, impl::prefix::femto>;
using picohenrys  = impl::swap_kind_prefix<henrys, impl::prefix::pico>;
using nanohenrys  = impl::swap_kind_prefix<henrys, impl::prefix::nano>;
using microhenrys = impl::swap_kind_prefix<henrys, impl::prefix::micro>;
using millihenrys = impl::swap_kind_prefix<henrys, impl::prefix::milli>;
using centihenrys = impl::swap_kind_prefix<henrys, impl::prefix::centi>;
using decihenrys  = impl::swap_kind_prefix<henrys, impl::prefix::deci>;
using nonehenrys  = impl::swap_kind_prefix<henrys, impl::prefix::none>;
using decahenrys  = impl::swap_kind_prefix<henrys, impl::prefix::deca>;
using hectohenrys = impl::swap_kind_prefix<henrys, impl::prefix::hecto>;
using kilohenrys  = impl::swap_kind_prefix<henrys, impl::prefix::kilo>;
using megahenrys  = impl::swap_kind_prefix<henrys, impl::prefix::mega>;
using gigahenrys  = impl::swap_kind_prefix<henrys, impl::prefix::giga>;
using terahenrys  = impl::swap_kind_prefix<henrys, impl::prefix::tera>;
using petahenrys  = impl::swap_kind_prefix<henrys, impl::prefix::peta>;
using exahenrys   = impl::swap_kind_prefix<henrys, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using henrys      = impl::magnitude<kind::henrys, double>;
using attohenrys  = impl::magnitude<kind::attohenrys, double>;
using femtohenrys = impl::magnitude<kind::femtohenrys, double>;
using picohenrys  = impl::magnitude<kind::picohenrys, double>;
using nanohenrys  = impl::magnitude<kind::nanohenrys, double>;
using microhenrys = impl::magnitude<kind::microhenrys, double>;
using millihenrys = impl::magnitude<kind::millihenrys, double>;
using centihenrys = impl::magnitude<kind::centihenrys, double>;
using decihenrys  = impl::magnitude<kind::decihenrys, double>;
using nonehenrys  = impl::magnitude<kind::nonehenrys, double>;
using decahenrys  = impl::magnitude<kind::decahenrys, double>;
using hectohenrys = impl::magnitude<kind::hectohenrys, double>;
using kilohenrys  = impl::magnitude<kind::kilohenrys, double>;
using megahenrys  = impl::magnitude<kind::megahenrys, double>;
using gigahenrys  = impl::magnitude<kind::gigahenrys, double>;
using terahenrys  = impl::magnitude<kind::terahenrys, double>;
using petahenrys  = impl::magnitude<kind::petahenrys, double>;
using exahenrys   = impl::magnitude<kind::exahenrys, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

