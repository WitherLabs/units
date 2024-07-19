#pragma once

#include <wither/units/force.hh>

namespace units
{

namespace kind
{

// clang-format off

using joules      = impl::multiply_kinds<newtons, metres>;
using attojoules  = impl::swap_kind_prefix<joules, impl::prefix::atto>;
using femtojoules = impl::swap_kind_prefix<joules, impl::prefix::femto>;
using picojoules  = impl::swap_kind_prefix<joules, impl::prefix::pico>;
using nanojoules  = impl::swap_kind_prefix<joules, impl::prefix::nano>;
using microjoules = impl::swap_kind_prefix<joules, impl::prefix::micro>;
using millijoules = impl::swap_kind_prefix<joules, impl::prefix::milli>;
using centijoules = impl::swap_kind_prefix<joules, impl::prefix::centi>;
using decijoules  = impl::swap_kind_prefix<joules, impl::prefix::deci>;
using nonejoules  = impl::swap_kind_prefix<joules, impl::prefix::none>;
using decajoules  = impl::swap_kind_prefix<joules, impl::prefix::deca>;
using hectojoules = impl::swap_kind_prefix<joules, impl::prefix::hecto>;
using kilojoules  = impl::swap_kind_prefix<joules, impl::prefix::kilo>;
using megajoules  = impl::swap_kind_prefix<joules, impl::prefix::mega>;
using gigajoules  = impl::swap_kind_prefix<joules, impl::prefix::giga>;
using terajoules  = impl::swap_kind_prefix<joules, impl::prefix::tera>;
using petajoules  = impl::swap_kind_prefix<joules, impl::prefix::peta>;
using exajoules   = impl::swap_kind_prefix<joules, impl::prefix::exa>;

using ergs = impl::multiply_kinds<dynes, centimetres>;
using kilowatt_hour = impl::derived_kind<megajoules, std::ratio<18, 5>>;
using british_thermal_unit = impl::derived_kind<joules, std::ratio<52753, 50>>;
using electronvolt = impl::derived_kind<picojoules, std::ratio<16021773, 100000000000>>;

// clang-format on

} // namespace kind

// clang-format off

using joules      = impl::magnitude<kind::joules, double>;
using attojoules  = impl::magnitude<kind::attojoules, double>;
using femtojoules = impl::magnitude<kind::femtojoules, double>;
using picojoules  = impl::magnitude<kind::picojoules, double>;
using nanojoules  = impl::magnitude<kind::nanojoules, double>;
using microjoules = impl::magnitude<kind::microjoules, double>;
using millijoules = impl::magnitude<kind::millijoules, double>;
using centijoules = impl::magnitude<kind::centijoules, double>;
using decijoules  = impl::magnitude<kind::decijoules, double>;
using nonejoules  = impl::magnitude<kind::nonejoules, double>;
using decajoules  = impl::magnitude<kind::decajoules, double>;
using hectojoules = impl::magnitude<kind::hectojoules, double>;
using kilojoules  = impl::magnitude<kind::kilojoules, double>;
using megajoules  = impl::magnitude<kind::megajoules, double>;
using gigajoules  = impl::magnitude<kind::gigajoules, double>;
using terajoules  = impl::magnitude<kind::terajoules, double>;
using petajoules  = impl::magnitude<kind::petajoules, double>;
using exajoules   = impl::magnitude<kind::exajoules, double>;

using ergs                 = impl::magnitude<kind::ergs, double>;
using kilowatt_hour        = impl::magnitude<kind::kilowatt_hour, double>;
using british_thermal_unit = impl::magnitude<kind::british_thermal_unit, double>;
using electronvolt         = impl::magnitude<kind::electronvolt, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

