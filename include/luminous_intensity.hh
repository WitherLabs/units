#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using luminous_intensity = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<0>, // length
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<1>  // luminous_intensity
    >;

} // namespace dimensions

using candelas = impl::basic<dimensions::luminous_intensity, long double>;

} // namespace units

