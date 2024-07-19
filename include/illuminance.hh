#pragma once

#include <wither/units/area.hh>
#include <wither/units/luminous_flux.hh>

namespace units
{

namespace kind
{

// clang-format off

using luxes      = impl::divide_kinds<lumens, metres_squared>;
using attoluxes  = impl::swap_kind_prefix<luxes, impl::prefix::atto>;
using femtoluxes = impl::swap_kind_prefix<luxes, impl::prefix::femto>;
using picoluxes  = impl::swap_kind_prefix<luxes, impl::prefix::pico>;
using nanoluxes  = impl::swap_kind_prefix<luxes, impl::prefix::nano>;
using microluxes = impl::swap_kind_prefix<luxes, impl::prefix::micro>;
using milliluxes = impl::swap_kind_prefix<luxes, impl::prefix::milli>;
using centiluxes = impl::swap_kind_prefix<luxes, impl::prefix::centi>;
using deciluxes  = impl::swap_kind_prefix<luxes, impl::prefix::deci>;
using noneluxes  = impl::swap_kind_prefix<luxes, impl::prefix::none>;
using decaluxes  = impl::swap_kind_prefix<luxes, impl::prefix::deca>;
using hectoluxes = impl::swap_kind_prefix<luxes, impl::prefix::hecto>;
using kiloluxes  = impl::swap_kind_prefix<luxes, impl::prefix::kilo>;
using megaluxes  = impl::swap_kind_prefix<luxes, impl::prefix::mega>;
using gigaluxes  = impl::swap_kind_prefix<luxes, impl::prefix::giga>;
using teraluxes  = impl::swap_kind_prefix<luxes, impl::prefix::tera>;
using petaluxes  = impl::swap_kind_prefix<luxes, impl::prefix::peta>;
using exaluxes   = impl::swap_kind_prefix<luxes, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using luxes      = impl::magnitude<kind::luxes, double>;
using attoluxes  = impl::magnitude<kind::attoluxes, double>;
using femtoluxes = impl::magnitude<kind::femtoluxes, double>;
using picoluxes  = impl::magnitude<kind::picoluxes, double>;
using nanoluxes  = impl::magnitude<kind::nanoluxes, double>;
using microluxes = impl::magnitude<kind::microluxes, double>;
using milliluxes = impl::magnitude<kind::milliluxes, double>;
using centiluxes = impl::magnitude<kind::centiluxes, double>;
using deciluxes  = impl::magnitude<kind::deciluxes, double>;
using noneluxes  = impl::magnitude<kind::noneluxes, double>;
using decaluxes  = impl::magnitude<kind::decaluxes, double>;
using hectoluxes = impl::magnitude<kind::hectoluxes, double>;
using kiloluxes  = impl::magnitude<kind::kiloluxes, double>;
using megaluxes  = impl::magnitude<kind::megaluxes, double>;
using gigaluxes  = impl::magnitude<kind::gigaluxes, double>;
using teraluxes  = impl::magnitude<kind::teraluxes, double>;
using petaluxes  = impl::magnitude<kind::petaluxes, double>;
using exaluxes   = impl::magnitude<kind::exaluxes, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

