#pragma once

#include <wither/units/units.hh>

namespace units
{

using substance_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<1>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{

using moles = impl::basic_kind<substance_dimension>;

} // namespace kind

using moles = impl::magnitude<kind::moles, double>;

} // namespace units

