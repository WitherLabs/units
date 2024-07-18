// vim: set ft=cpp:

#pragma once

#include <wither/units/units.hh>

namespace units
{

using temperature_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<1>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{
using kelvin  = impl::basic_kind<temperature_dimension>;
using celsius = impl::
    derived_kind<kelvin, impl::ratio::base, std::ratio<27315, 100>>::value;
using fahrenheit
    = impl::derived_kind<celsius, std::ratio<5, 9>, std::ratio<-160, 9>>::value;

} // namespace kind

using kelvin     = impl::magnitude<kind::kelvin, double>;
using celsius    = impl::magnitude<kind::celsius, double>;
using fahrenheit = impl::magnitude<kind::fahrenheit, double>;

} // namespace units

