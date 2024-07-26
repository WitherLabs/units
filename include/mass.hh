#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using mass = impl::dimension<
    std::ratio<1>, // mass
    std::ratio<0>, // length
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using grams = impl::basic<dimensions::mass, long double>;

} // namespace units

