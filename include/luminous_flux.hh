#pragma once

#include <wither/units/luminous_intensity.hh>
#include <wither/units/solid_angle.hh>

namespace units
{

namespace kind
{

// clang-format off

using lumens      = impl::multiply_kinds<candelas, steradians>;
using attolumens  = impl::swap_kind_prefix<lumens, impl::prefix::atto>;
using femtolumens = impl::swap_kind_prefix<lumens, impl::prefix::femto>;
using picolumens  = impl::swap_kind_prefix<lumens, impl::prefix::pico>;
using nanolumens  = impl::swap_kind_prefix<lumens, impl::prefix::nano>;
using microlumens = impl::swap_kind_prefix<lumens, impl::prefix::micro>;
using millilumens = impl::swap_kind_prefix<lumens, impl::prefix::milli>;
using centilumens = impl::swap_kind_prefix<lumens, impl::prefix::centi>;
using decilumens  = impl::swap_kind_prefix<lumens, impl::prefix::deci>;
using nonelumens  = impl::swap_kind_prefix<lumens, impl::prefix::none>;
using decalumens  = impl::swap_kind_prefix<lumens, impl::prefix::deca>;
using hectolumens = impl::swap_kind_prefix<lumens, impl::prefix::hecto>;
using kilolumens  = impl::swap_kind_prefix<lumens, impl::prefix::kilo>;
using megalumens  = impl::swap_kind_prefix<lumens, impl::prefix::mega>;
using gigalumens  = impl::swap_kind_prefix<lumens, impl::prefix::giga>;
using teralumens  = impl::swap_kind_prefix<lumens, impl::prefix::tera>;
using petalumens  = impl::swap_kind_prefix<lumens, impl::prefix::peta>;
using exalumens   = impl::swap_kind_prefix<lumens, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using lumens      = impl::magnitude<kind::lumens, double>;
using attolumens  = impl::magnitude<kind::attolumens, double>;
using femtolumens = impl::magnitude<kind::femtolumens, double>;
using picolumens  = impl::magnitude<kind::picolumens, double>;
using nanolumens  = impl::magnitude<kind::nanolumens, double>;
using microlumens = impl::magnitude<kind::microlumens, double>;
using millilumens = impl::magnitude<kind::millilumens, double>;
using centilumens = impl::magnitude<kind::centilumens, double>;
using decilumens  = impl::magnitude<kind::decilumens, double>;
using nonelumens  = impl::magnitude<kind::nonelumens, double>;
using decalumens  = impl::magnitude<kind::decalumens, double>;
using hectolumens = impl::magnitude<kind::hectolumens, double>;
using kilolumens  = impl::magnitude<kind::kilolumens, double>;
using megalumens  = impl::magnitude<kind::megalumens, double>;
using gigalumens  = impl::magnitude<kind::gigalumens, double>;
using teralumens  = impl::magnitude<kind::teralumens, double>;
using petalumens  = impl::magnitude<kind::petalumens, double>;
using exalumens   = impl::magnitude<kind::exalumens, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

