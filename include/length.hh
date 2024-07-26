#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using length = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<1>, // length
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using metres = impl::basic<dimensions::length, long double>;

} // namespace units

