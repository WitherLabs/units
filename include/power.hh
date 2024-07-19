#pragma once

#include <wither/units/energy.hh>

namespace units
{

namespace kind
{

// clang-format off

using watts      = impl::divide_kinds<joules, seconds>;
using attowatts  = impl::swap_kind_prefix<watts, impl::prefix::atto>;
using femtowatts = impl::swap_kind_prefix<watts, impl::prefix::femto>;
using picowatts  = impl::swap_kind_prefix<watts, impl::prefix::pico>;
using nanowatts  = impl::swap_kind_prefix<watts, impl::prefix::nano>;
using microwatts = impl::swap_kind_prefix<watts, impl::prefix::micro>;
using milliwatts = impl::swap_kind_prefix<watts, impl::prefix::milli>;
using centiwatts = impl::swap_kind_prefix<watts, impl::prefix::centi>;
using deciwatts  = impl::swap_kind_prefix<watts, impl::prefix::deci>;
using nonewatts  = impl::swap_kind_prefix<watts, impl::prefix::none>;
using decawatts  = impl::swap_kind_prefix<watts, impl::prefix::deca>;
using hectowatts = impl::swap_kind_prefix<watts, impl::prefix::hecto>;
using kilowatts  = impl::swap_kind_prefix<watts, impl::prefix::kilo>;
using megawatts  = impl::swap_kind_prefix<watts, impl::prefix::mega>;
using gigawatts  = impl::swap_kind_prefix<watts, impl::prefix::giga>;
using terawatts  = impl::swap_kind_prefix<watts, impl::prefix::tera>;
using petawatts  = impl::swap_kind_prefix<watts, impl::prefix::peta>;
using exawatts   = impl::swap_kind_prefix<watts, impl::prefix::exa>;

using imperial_horsepower = impl::derived_kind<watts, std::ratio<7457, 10>>;
using horsepower = impl::derived_kind<watts, std::ratio<73549875, 100000>>;

// clang-format on

} // namespace kind

// clang-format off

using watts      = impl::magnitude<kind::watts, double>;
using attowatts  = impl::magnitude<kind::attowatts, double>;
using femtowatts = impl::magnitude<kind::femtowatts, double>;
using picowatts  = impl::magnitude<kind::picowatts, double>;
using nanowatts  = impl::magnitude<kind::nanowatts, double>;
using microwatts = impl::magnitude<kind::microwatts, double>;
using milliwatts = impl::magnitude<kind::milliwatts, double>;
using centiwatts = impl::magnitude<kind::centiwatts, double>;
using deciwatts  = impl::magnitude<kind::deciwatts, double>;
using nonewatts  = impl::magnitude<kind::nonewatts, double>;
using decawatts  = impl::magnitude<kind::decawatts, double>;
using hectowatts = impl::magnitude<kind::hectowatts, double>;
using kilowatts  = impl::magnitude<kind::kilowatts, double>;
using megawatts  = impl::magnitude<kind::megawatts, double>;
using gigawatts  = impl::magnitude<kind::gigawatts, double>;
using terawatts  = impl::magnitude<kind::terawatts, double>;
using petawatts  = impl::magnitude<kind::petawatts, double>;
using exawatts   = impl::magnitude<kind::exawatts, double>;

using imperial_horsepower = impl::magnitude<kind::imperial_horsepower, double>;
using horsepower          = impl::magnitude<kind::horsepower, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

