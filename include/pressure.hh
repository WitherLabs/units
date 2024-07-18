#pragma once

#include <wither/units/area.hh>
#include <wither/units/force.hh>

namespace units
{

namespace kind
{

// clang-format off

using pascals      = impl::divide_kinds<newtons, metres_squared>;
using attopascals  = impl::swap_kind_prefix<pascals, impl::prefix::atto>;
using femtopascals = impl::swap_kind_prefix<pascals, impl::prefix::femto>;
using picopascals  = impl::swap_kind_prefix<pascals, impl::prefix::pico>;
using nanopascals  = impl::swap_kind_prefix<pascals, impl::prefix::nano>;
using micropascals = impl::swap_kind_prefix<pascals, impl::prefix::micro>;
using millipascals = impl::swap_kind_prefix<pascals, impl::prefix::milli>;
using centipascals = impl::swap_kind_prefix<pascals, impl::prefix::centi>;
using decipascals  = impl::swap_kind_prefix<pascals, impl::prefix::deci>;
using nonepascals  = impl::swap_kind_prefix<pascals, impl::prefix::none>;
using decapascals  = impl::swap_kind_prefix<pascals, impl::prefix::deca>;
using hectopascals = impl::swap_kind_prefix<pascals, impl::prefix::hecto>;
using kilopascals  = impl::swap_kind_prefix<pascals, impl::prefix::kilo>;
using megapascals  = impl::swap_kind_prefix<pascals, impl::prefix::mega>;
using gigapascals  = impl::swap_kind_prefix<pascals, impl::prefix::giga>;
using terapascals  = impl::swap_kind_prefix<pascals, impl::prefix::tera>;
using petapascals  = impl::swap_kind_prefix<pascals, impl::prefix::peta>;
using exapascals   = impl::swap_kind_prefix<pascals, impl::prefix::exa>;

using bars                   = impl::swap_kind_prefix<pascals, std::ratio<100000000>>;
using baryes                 = impl::divide_kinds<dynes, centimetres_squared>;
using atmospheres            = impl::derived_kind<pascals, std::ratio<101325>>;
using torrs                  = impl::derived_kind<atmospheres, std::ratio<1, 760>>;
using pounds_per_square_inch = impl::divide_kinds<pounds_of_force, inches_squared>;

// clang-format on

} // namespace kind

// clang-format off

using pascals      = impl::magnitude<kind::pascals, double>;
using attopascals  = impl::magnitude<kind::attopascals, double>;
using femtopascals = impl::magnitude<kind::femtopascals, double>;
using picopascals  = impl::magnitude<kind::picopascals, double>;
using nanopascals  = impl::magnitude<kind::nanopascals, double>;
using micropascals = impl::magnitude<kind::micropascals, double>;
using millipascals = impl::magnitude<kind::millipascals, double>;
using centipascals = impl::magnitude<kind::centipascals, double>;
using decipascals  = impl::magnitude<kind::decipascals, double>;
using nonepascals  = impl::magnitude<kind::nonepascals, double>;
using decapascals  = impl::magnitude<kind::decapascals, double>;
using hectopascals = impl::magnitude<kind::hectopascals, double>;
using kilopascals  = impl::magnitude<kind::kilopascals, double>;
using megapascals  = impl::magnitude<kind::megapascals, double>;
using gigapascals  = impl::magnitude<kind::gigapascals, double>;
using terapascals  = impl::magnitude<kind::terapascals, double>;
using petapascals  = impl::magnitude<kind::petapascals, double>;
using exapascals   = impl::magnitude<kind::exapascals, double>;

using bars                   = impl::magnitude<kind::bars, double>;
using baryes                 = impl::magnitude<kind::baryes, double>;
using atmospheres            = impl::magnitude<kind::atmospheres, double>;
using torrs                  = impl::magnitude<kind::torrs, double>;
using pounds_per_square_inch = impl::magnitude<kind::pounds_per_square_inch, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

