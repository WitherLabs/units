#pragma once

#include <wither/units/frequency.hh>

namespace units
{

namespace kind
{

// clang-format off

using becquerels      = impl::clone_kind<hertz>;
using attobecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::atto>;
using femtobecquerels = impl::swap_kind_prefix<becquerels, impl::prefix::femto>;
using picobecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::pico>;
using nanobecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::nano>;
using microbecquerels = impl::swap_kind_prefix<becquerels, impl::prefix::micro>;
using millibecquerels = impl::swap_kind_prefix<becquerels, impl::prefix::milli>;
using centibecquerels = impl::swap_kind_prefix<becquerels, impl::prefix::centi>;
using decibecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::deci>;
using nonebecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::none>;
using decabecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::deca>;
using hectobecquerels = impl::swap_kind_prefix<becquerels, impl::prefix::hecto>;
using kilobecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::kilo>;
using megabecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::mega>;
using gigabecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::giga>;
using terabecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::tera>;
using petabecquerels  = impl::swap_kind_prefix<becquerels, impl::prefix::peta>;
using exabecquerels   = impl::swap_kind_prefix<becquerels, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using becquerels      = impl::magnitude<kind::becquerels, double>;
using attobecquerels  = impl::magnitude<kind::attobecquerels, double>;
using femtobecquerels = impl::magnitude<kind::femtobecquerels, double>;
using picobecquerels  = impl::magnitude<kind::picobecquerels, double>;
using nanobecquerels  = impl::magnitude<kind::nanobecquerels, double>;
using microbecquerels = impl::magnitude<kind::microbecquerels, double>;
using millibecquerels = impl::magnitude<kind::millibecquerels, double>;
using centibecquerels = impl::magnitude<kind::centibecquerels, double>;
using decibecquerels  = impl::magnitude<kind::decibecquerels, double>;
using nonebecquerels  = impl::magnitude<kind::nonebecquerels, double>;
using decabecquerels  = impl::magnitude<kind::decabecquerels, double>;
using hectobecquerels = impl::magnitude<kind::hectobecquerels, double>;
using kilobecquerels  = impl::magnitude<kind::kilobecquerels, double>;
using megabecquerels  = impl::magnitude<kind::megabecquerels, double>;
using gigabecquerels  = impl::magnitude<kind::gigabecquerels, double>;
using terabecquerels  = impl::magnitude<kind::terabecquerels, double>;
using petabecquerels  = impl::magnitude<kind::petabecquerels, double>;
using exabecquerels   = impl::magnitude<kind::exabecquerels, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

