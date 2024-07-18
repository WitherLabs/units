// vim: set ft=cpp:

#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dim
{

using temperature = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<1>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

} // namespace dim

namespace kind
{

using kelvin = impl::basic_kind<dim::temperature>;

using attokelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::atto>;
using femtokelvin = impl::swap_kind_prefix<kelvin, impl::prefix::femto>;
using picokelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::pico>;
using nanokelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::nano>;
using microkelvin = impl::swap_kind_prefix<kelvin, impl::prefix::micro>;
using millikelvin = impl::swap_kind_prefix<kelvin, impl::prefix::milli>;
using centikelvin = impl::swap_kind_prefix<kelvin, impl::prefix::centi>;
using decikelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::deci>;
using nonekelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::none>;
using decakelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::deca>;
using hectokelvin = impl::swap_kind_prefix<kelvin, impl::prefix::hecto>;
using kilokelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::kilo>;
using megakelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::mega>;
using gigakelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::giga>;
using terakelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::tera>;
using petakelvin  = impl::swap_kind_prefix<kelvin, impl::prefix::peta>;
using exakelvin   = impl::swap_kind_prefix<kelvin, impl::prefix::exa>;

using celsius = impl::
    derived_kind<kelvin, impl::ratio::base, std::ratio<5463, 20>>::value;

using fahrenheit
    = impl::derived_kind<celsius, std::ratio<5, 9>, std::ratio<-160, 9>>::value;

} // namespace kind

using kelvin = impl::magnitude<kind::kelvin, double>;

using attokelvin  = impl::magnitude<kind::attokelvin, double>;
using femtokelvin = impl::magnitude<kind::femtokelvin, double>;
using picokelvin  = impl::magnitude<kind::picokelvin, double>;
using nanokelvin  = impl::magnitude<kind::nanokelvin, double>;
using microkelvin = impl::magnitude<kind::microkelvin, double>;
using millikelvin = impl::magnitude<kind::millikelvin, double>;
using centikelvin = impl::magnitude<kind::centikelvin, double>;
using decikelvin  = impl::magnitude<kind::decikelvin, double>;
using nonekelvin  = impl::magnitude<kind::nonekelvin, double>;
using decakelvin  = impl::magnitude<kind::decakelvin, double>;
using hectokelvin = impl::magnitude<kind::hectokelvin, double>;
using kilokelvin  = impl::magnitude<kind::kilokelvin, double>;
using megakelvin  = impl::magnitude<kind::megakelvin, double>;
using gigakelvin  = impl::magnitude<kind::gigakelvin, double>;
using terakelvin  = impl::magnitude<kind::terakelvin, double>;
using petakelvin  = impl::magnitude<kind::petakelvin, double>;
using exakelvin   = impl::magnitude<kind::exakelvin, double>;

using celsius    = impl::magnitude<kind::celsius, double>;
using fahrenheit = impl::magnitude<kind::fahrenheit, double>;

} // namespace units

