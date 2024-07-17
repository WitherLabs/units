#pragma once

#include <wither/units/units.hh>

namespace units
{

using mass_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<1>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{

using grams    = impl::basic_kind<mass_dimension>;
using pounds   = impl::derived_kind<grams, std::ratio<45359237, 100000>>::value;
using grains   = impl::derived_kind<pounds, std::ratio<1, 7000>>::value;
using drachms  = impl::derived_kind<pounds, std::ratio<1, 256>>::value;
using ounces   = impl::derived_kind<pounds, std::ratio<1, 16>>::value;
using stones   = impl::derived_kind<pounds, std::ratio<14>>::value;
using quarters = impl::derived_kind<pounds, std::ratio<28>>::value;
using hundredweights = impl::derived_kind<pounds, std::ratio<112>>::value;
using tons           = impl::derived_kind<pounds, std::ratio<2240>>::value;

} // namespace kind

using grams          = impl::magnitude<kind::grams, double>;
using pounds         = impl::magnitude<kind::pounds, double>;
using grains         = impl::magnitude<kind::grains, double>;
using drachms        = impl::magnitude<kind::drachms, double>;
using ounces         = impl::magnitude<kind::ounces, double>;
using stones         = impl::magnitude<kind::stones, double>;
using quarters       = impl::magnitude<kind::quarters, double>;
using hundredweights = impl::magnitude<kind::hundredweights, double>;
using tons           = impl::magnitude<kind::tons, double>;

} // namespace units

