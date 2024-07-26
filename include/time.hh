#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using time = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<0>, // length
    std::ratio<1>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using seconds = impl::basic<dimensions::time, long double>;

} // namespace units

