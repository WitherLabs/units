#pragma once

#include <wither/units/units.hh>

namespace units
{

using current_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<1>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{

using amperes = impl::basic_kind<current_dimension>;

} // namespace kind

using amperes = impl::magnitude<kind::amperes, double>;

} // namespace units

