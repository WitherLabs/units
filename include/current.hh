#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using current = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<0>, // length
    std::ratio<0>, // time
    std::ratio<1>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using amperes = impl::basic<dimensions::current, long double>;

} // namespace units

