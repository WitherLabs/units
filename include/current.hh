#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dim
{

using current = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<1>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

} // namespace dim

namespace kind
{

using amperes = impl::basic_kind<dim::current>;

using attoamperes  = impl::swap_kind_prefix<amperes, impl::prefix::atto>;
using femtoamperes = impl::swap_kind_prefix<amperes, impl::prefix::femto>;
using picoamperes  = impl::swap_kind_prefix<amperes, impl::prefix::pico>;
using nanoamperes  = impl::swap_kind_prefix<amperes, impl::prefix::nano>;
using microamperes = impl::swap_kind_prefix<amperes, impl::prefix::micro>;
using milliamperes = impl::swap_kind_prefix<amperes, impl::prefix::milli>;
using centiamperes = impl::swap_kind_prefix<amperes, impl::prefix::centi>;
using deciamperes  = impl::swap_kind_prefix<amperes, impl::prefix::deci>;
using noneamperes  = impl::swap_kind_prefix<amperes, impl::prefix::none>;
using decaamperes  = impl::swap_kind_prefix<amperes, impl::prefix::deca>;
using hectoamperes = impl::swap_kind_prefix<amperes, impl::prefix::hecto>;
using kiloamperes  = impl::swap_kind_prefix<amperes, impl::prefix::kilo>;
using megaamperes  = impl::swap_kind_prefix<amperes, impl::prefix::mega>;
using gigaamperes  = impl::swap_kind_prefix<amperes, impl::prefix::giga>;
using teraamperes  = impl::swap_kind_prefix<amperes, impl::prefix::tera>;
using petaamperes  = impl::swap_kind_prefix<amperes, impl::prefix::peta>;
using exaamperes   = impl::swap_kind_prefix<amperes, impl::prefix::exa>;

} // namespace kind

using amperes = impl::magnitude<kind::amperes, double>;

using attoamperes  = impl::magnitude<kind::attoamperes, double>;
using femtoamperes = impl::magnitude<kind::femtoamperes, double>;
using picoamperes  = impl::magnitude<kind::picoamperes, double>;
using nanoamperes  = impl::magnitude<kind::nanoamperes, double>;
using microamperes = impl::magnitude<kind::microamperes, double>;
using milliamperes = impl::magnitude<kind::milliamperes, double>;
using centiamperes = impl::magnitude<kind::centiamperes, double>;
using deciamperes  = impl::magnitude<kind::deciamperes, double>;
using noneamperes  = impl::magnitude<kind::noneamperes, double>;
using decaamperes  = impl::magnitude<kind::decaamperes, double>;
using hectoamperes = impl::magnitude<kind::hectoamperes, double>;
using kiloamperes  = impl::magnitude<kind::kiloamperes, double>;
using megaamperes  = impl::magnitude<kind::megaamperes, double>;
using gigaamperes  = impl::magnitude<kind::gigaamperes, double>;
using teraamperes  = impl::magnitude<kind::teraamperes, double>;
using petaamperes  = impl::magnitude<kind::petaamperes, double>;
using exaamperes   = impl::magnitude<kind::exaamperes, double>;

} // namespace units

