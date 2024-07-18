#pragma once

#include <wither/units/acceleration.hh>
#include <wither/units/mass.hh>

namespace units
{

namespace kind
{

// clang-format off

using newtons      = impl::multiply_kinds<metres_per_second_squared, kilograms>;
using attonewtons  = impl::swap_kind_prefix<newtons, impl::prefix::atto>;
using femtonewtons = impl::swap_kind_prefix<newtons, impl::prefix::femto>;
using piconewtons  = impl::swap_kind_prefix<newtons, impl::prefix::pico>;
using nanonewtons  = impl::swap_kind_prefix<newtons, impl::prefix::nano>;
using micronewtons = impl::swap_kind_prefix<newtons, impl::prefix::micro>;
using millinewtons = impl::swap_kind_prefix<newtons, impl::prefix::milli>;
using centinewtons = impl::swap_kind_prefix<newtons, impl::prefix::centi>;
using decinewtons  = impl::swap_kind_prefix<newtons, impl::prefix::deci>;
using nonenewtons  = impl::swap_kind_prefix<newtons, impl::prefix::none>;
using decanewtons  = impl::swap_kind_prefix<newtons, impl::prefix::deca>;
using hectonewtons = impl::swap_kind_prefix<newtons, impl::prefix::hecto>;
using kilonewtons  = impl::swap_kind_prefix<newtons, impl::prefix::kilo>;
using meganewtons  = impl::swap_kind_prefix<newtons, impl::prefix::mega>;
using giganewtons  = impl::swap_kind_prefix<newtons, impl::prefix::giga>;
using teranewtons  = impl::swap_kind_prefix<newtons, impl::prefix::tera>;
using petanewtons  = impl::swap_kind_prefix<newtons, impl::prefix::peta>;
using exanewtons   = impl::swap_kind_prefix<newtons, impl::prefix::exa>;

using dynes           = impl::multiply_kinds<grams, centimetres_per_second_squared>;
using kilopond        = impl::derived_kind<dynes, std::ratio<980665>>;
using pounds_of_force = impl::derived_kind<dynes, std::ratio<444822>>;
using poundals        = impl::derived_kind<dynes, std::ratio<13825>>;

// clang-format on

} // namespace kind

// clang-format off

using newtons      = impl::magnitude<kind::newtons, double>;
using attonewtons  = impl::magnitude<kind::attonewtons, double>;
using femtonewtons = impl::magnitude<kind::femtonewtons, double>;
using piconewtons  = impl::magnitude<kind::piconewtons, double>;
using nanonewtons  = impl::magnitude<kind::nanonewtons, double>;
using micronewtons = impl::magnitude<kind::micronewtons, double>;
using millinewtons = impl::magnitude<kind::millinewtons, double>;
using centinewtons = impl::magnitude<kind::centinewtons, double>;
using decinewtons  = impl::magnitude<kind::decinewtons, double>;
using nonenewtons  = impl::magnitude<kind::nonenewtons, double>;
using decanewtons  = impl::magnitude<kind::decanewtons, double>;
using hectonewtons = impl::magnitude<kind::hectonewtons, double>;
using kilonewtons  = impl::magnitude<kind::kilonewtons, double>;
using meganewtons  = impl::magnitude<kind::meganewtons, double>;
using giganewtons  = impl::magnitude<kind::giganewtons, double>;
using teranewtons  = impl::magnitude<kind::teranewtons, double>;
using petanewtons  = impl::magnitude<kind::petanewtons, double>;
using exanewtons   = impl::magnitude<kind::exanewtons, double>;

using kilopond        = impl::magnitude<kind::kilopond, double>;
using pounds_of_force = impl::magnitude<kind::pounds_of_force, double>;
using poundals        = impl::magnitude<kind::poundals, double>;
using dynes           = impl::magnitude<kind::dynes, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

