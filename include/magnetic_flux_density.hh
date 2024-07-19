#pragma once

#include <wither/units/area.hh>
#include <wither/units/magnetic_flux.hh>

namespace units
{

namespace kind
{

// clang-format off

using teslas      = impl::divide_kinds<webers, metres_squared>;
using attoteslas  = impl::swap_kind_prefix<teslas, impl::prefix::atto>;
using femtoteslas = impl::swap_kind_prefix<teslas, impl::prefix::femto>;
using picoteslas  = impl::swap_kind_prefix<teslas, impl::prefix::pico>;
using nanoteslas  = impl::swap_kind_prefix<teslas, impl::prefix::nano>;
using microteslas = impl::swap_kind_prefix<teslas, impl::prefix::micro>;
using milliteslas = impl::swap_kind_prefix<teslas, impl::prefix::milli>;
using centiteslas = impl::swap_kind_prefix<teslas, impl::prefix::centi>;
using deciteslas  = impl::swap_kind_prefix<teslas, impl::prefix::deci>;
using noneteslas  = impl::swap_kind_prefix<teslas, impl::prefix::none>;
using decateslas  = impl::swap_kind_prefix<teslas, impl::prefix::deca>;
using hectoteslas = impl::swap_kind_prefix<teslas, impl::prefix::hecto>;
using kiloteslas  = impl::swap_kind_prefix<teslas, impl::prefix::kilo>;
using megateslas  = impl::swap_kind_prefix<teslas, impl::prefix::mega>;
using gigateslas  = impl::swap_kind_prefix<teslas, impl::prefix::giga>;
using terateslas  = impl::swap_kind_prefix<teslas, impl::prefix::tera>;
using petateslas  = impl::swap_kind_prefix<teslas, impl::prefix::peta>;
using exateslas   = impl::swap_kind_prefix<teslas, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using teslas      = impl::magnitude<kind::teslas, double>;
using attoteslas  = impl::magnitude<kind::attoteslas, double>;
using femtoteslas = impl::magnitude<kind::femtoteslas, double>;
using picoteslas  = impl::magnitude<kind::picoteslas, double>;
using nanoteslas  = impl::magnitude<kind::nanoteslas, double>;
using microteslas = impl::magnitude<kind::microteslas, double>;
using milliteslas = impl::magnitude<kind::milliteslas, double>;
using centiteslas = impl::magnitude<kind::centiteslas, double>;
using deciteslas  = impl::magnitude<kind::deciteslas, double>;
using noneteslas  = impl::magnitude<kind::noneteslas, double>;
using decateslas  = impl::magnitude<kind::decateslas, double>;
using hectoteslas = impl::magnitude<kind::hectoteslas, double>;
using kiloteslas  = impl::magnitude<kind::kiloteslas, double>;
using megateslas  = impl::magnitude<kind::megateslas, double>;
using gigateslas  = impl::magnitude<kind::gigateslas, double>;
using terateslas  = impl::magnitude<kind::terateslas, double>;
using petateslas  = impl::magnitude<kind::petateslas, double>;
using exateslas   = impl::magnitude<kind::exateslas, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

