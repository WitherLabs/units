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

using kelvins         = impl::basic<dimensions::temperature, long double>;
using degrees_celsius = impl::derive_delta<std::ratio<27315, 100>, kelvins>;

} // namespace units

