#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using temperature = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<0>, // length
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<1>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using kelvins = impl::basic<dimensions::temperature, long double>;

} // namespace units

