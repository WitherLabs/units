#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dimensions
{

using substance = impl::dimension<
    std::ratio<0>, // mass
    std::ratio<0>, // length
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<1>, // substance
    std::ratio<0>  // luminous_intensity
    >;

} // namespace dimensions

using moles = impl::basic<dimensions::substance, long double>;

} // namespace units

