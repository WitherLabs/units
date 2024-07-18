#pragma once

#include <wither/units/units.hh>

namespace units
{

using luminous_intensity_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<1>  // luminous intensity
    >;

namespace kind
{

using candelas = impl::basic_kind<luminous_intensity_dimension>;

} // namespace kind

using candelas = impl::magnitude<kind::candelas, double>;

} // namespace units

