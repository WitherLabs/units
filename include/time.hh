#pragma once

#include <wither/units/units.hh>

namespace units
{

using time_dimension = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<1>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{

using seconds = impl::basic_kind<time_dimension>;

using minutes    = impl::derived_kind<seconds, std::ratio<60>>::value;
using hours      = impl::derived_kind<minutes, std::ratio<60>>::value;
using days       = impl::derived_kind<hours, std::ratio<24>>::value;
using weeks      = impl::derived_kind<days, std::ratio<7>>::value;
using months_28  = impl::derived_kind<days, std::ratio<28>>::value;
using months_29  = impl::derived_kind<days, std::ratio<29>>::value;
using months_30  = impl::derived_kind<days, std::ratio<30>>::value;
using months_31  = impl::derived_kind<days, std::ratio<31>>::value;
using years      = impl::derived_kind<days, std::ratio<365>>::value;
using leap_years = impl::derived_kind<days, std::ratio<366>>::value;
using decades    = impl::derived_kind<years, std::ratio<10>>::value;
using centuries  = impl::derived_kind<years, std::ratio<100>>::value;
using eons       = impl::derived_kind<years, std::ratio<1000000000>>::value;

} // namespace kind

using minutes    = impl::magnitude<kind::minutes, double>;
using hours      = impl::magnitude<kind::hours, double>;
using days       = impl::magnitude<kind::days, double>;
using weeks      = impl::magnitude<kind::weeks, double>;
using months_28  = impl::magnitude<kind::months_28, double>;
using months_29  = impl::magnitude<kind::months_29, double>;
using months_30  = impl::magnitude<kind::months_30, double>;
using months_31  = impl::magnitude<kind::months_31, double>;
using years      = impl::magnitude<kind::years, double>;
using leap_years = impl::magnitude<kind::leap_years, double>;
using decades    = impl::magnitude<kind::decades, double>;
using centuries  = impl::magnitude<kind::centuries, double>;
using eons       = impl::magnitude<kind::eons, double>;

} // namespace units

