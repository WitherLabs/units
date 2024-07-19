#pragma once

#include <wither/units/energy.hh>

namespace units
{

namespace kind
{

// clang-format off

using grays      = impl::divide_kinds<joules, kilograms>;
using attograys  = impl::swap_kind_prefix<grays, impl::prefix::atto>;
using femtograys = impl::swap_kind_prefix<grays, impl::prefix::femto>;
using picograys  = impl::swap_kind_prefix<grays, impl::prefix::pico>;
using nanograys  = impl::swap_kind_prefix<grays, impl::prefix::nano>;
using micrograys = impl::swap_kind_prefix<grays, impl::prefix::micro>;
using milligrays = impl::swap_kind_prefix<grays, impl::prefix::milli>;
using centigrays = impl::swap_kind_prefix<grays, impl::prefix::centi>;
using decigrays  = impl::swap_kind_prefix<grays, impl::prefix::deci>;
using nonegrays  = impl::swap_kind_prefix<grays, impl::prefix::none>;
using decagrays  = impl::swap_kind_prefix<grays, impl::prefix::deca>;
using hectograys = impl::swap_kind_prefix<grays, impl::prefix::hecto>;
using kilograys  = impl::swap_kind_prefix<grays, impl::prefix::kilo>;
using megagrays  = impl::swap_kind_prefix<grays, impl::prefix::mega>;
using gigagrays  = impl::swap_kind_prefix<grays, impl::prefix::giga>;
using teragrays  = impl::swap_kind_prefix<grays, impl::prefix::tera>;
using petagrays  = impl::swap_kind_prefix<grays, impl::prefix::peta>;
using exagrays   = impl::swap_kind_prefix<grays, impl::prefix::exa>;

using sieverts      = impl::divide_kinds<joules, kilograms>;
using attosieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::atto>;
using femtosieverts = impl::swap_kind_prefix<sieverts, impl::prefix::femto>;
using picosieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::pico>;
using nanosieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::nano>;
using microsieverts = impl::swap_kind_prefix<sieverts, impl::prefix::micro>;
using millisieverts = impl::swap_kind_prefix<sieverts, impl::prefix::milli>;
using centisieverts = impl::swap_kind_prefix<sieverts, impl::prefix::centi>;
using decisieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::deci>;
using nonesieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::none>;
using decasieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::deca>;
using hectosieverts = impl::swap_kind_prefix<sieverts, impl::prefix::hecto>;
using kilosieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::kilo>;
using megasieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::mega>;
using gigasieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::giga>;
using terasieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::tera>;
using petasieverts  = impl::swap_kind_prefix<sieverts, impl::prefix::peta>;
using exasieverts   = impl::swap_kind_prefix<sieverts, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using grays      = impl::magnitude<kind::grays, double>;
using attograys  = impl::magnitude<kind::attograys, double>;
using femtograys = impl::magnitude<kind::femtograys, double>;
using picograys  = impl::magnitude<kind::picograys, double>;
using nanograys  = impl::magnitude<kind::nanograys, double>;
using micrograys = impl::magnitude<kind::micrograys, double>;
using milligrays = impl::magnitude<kind::milligrays, double>;
using centigrays = impl::magnitude<kind::centigrays, double>;
using decigrays  = impl::magnitude<kind::decigrays, double>;
using nonegrays  = impl::magnitude<kind::nonegrays, double>;
using decagrays  = impl::magnitude<kind::decagrays, double>;
using hectograys = impl::magnitude<kind::hectograys, double>;
using kilograys  = impl::magnitude<kind::kilograys, double>;
using megagrays  = impl::magnitude<kind::megagrays, double>;
using gigagrays  = impl::magnitude<kind::gigagrays, double>;
using teragrays  = impl::magnitude<kind::teragrays, double>;
using petagrays  = impl::magnitude<kind::petagrays, double>;
using exagrays   = impl::magnitude<kind::exagrays, double>;

using sieverts      = impl::magnitude<kind::sieverts, double>;
using attosieverts  = impl::magnitude<kind::attosieverts, double>;
using femtosieverts = impl::magnitude<kind::femtosieverts, double>;
using picosieverts  = impl::magnitude<kind::picosieverts, double>;
using nanosieverts  = impl::magnitude<kind::nanosieverts, double>;
using microsieverts = impl::magnitude<kind::microsieverts, double>;
using millisieverts = impl::magnitude<kind::millisieverts, double>;
using centisieverts = impl::magnitude<kind::centisieverts, double>;
using decisieverts  = impl::magnitude<kind::decisieverts, double>;
using nonesieverts  = impl::magnitude<kind::nonesieverts, double>;
using decasieverts  = impl::magnitude<kind::decasieverts, double>;
using hectosieverts = impl::magnitude<kind::hectosieverts, double>;
using kilosieverts  = impl::magnitude<kind::kilosieverts, double>;
using megasieverts  = impl::magnitude<kind::megasieverts, double>;
using gigasieverts  = impl::magnitude<kind::gigasieverts, double>;
using terasieverts  = impl::magnitude<kind::terasieverts, double>;
using petasieverts  = impl::magnitude<kind::petasieverts, double>;
using exasieverts   = impl::magnitude<kind::exasieverts, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

