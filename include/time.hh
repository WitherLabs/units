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

using attoseconds  = impl::swap_kind_prefix<seconds, impl::prefix::atto>;
using femtoseconds = impl::swap_kind_prefix<seconds, impl::prefix::femto>;
using picoseconds  = impl::swap_kind_prefix<seconds, impl::prefix::pico>;
using nanoseconds  = impl::swap_kind_prefix<seconds, impl::prefix::nano>;
using microseconds = impl::swap_kind_prefix<seconds, impl::prefix::micro>;
using milliseconds = impl::swap_kind_prefix<seconds, impl::prefix::milli>;
using centiseconds = impl::swap_kind_prefix<seconds, impl::prefix::centi>;
using deciseconds  = impl::swap_kind_prefix<seconds, impl::prefix::deci>;
using noneseconds  = impl::swap_kind_prefix<seconds, impl::prefix::none>;
using decaseconds  = impl::swap_kind_prefix<seconds, impl::prefix::deca>;
using hectoseconds = impl::swap_kind_prefix<seconds, impl::prefix::hecto>;
using kiloseconds  = impl::swap_kind_prefix<seconds, impl::prefix::kilo>;
using megaseconds  = impl::swap_kind_prefix<seconds, impl::prefix::mega>;
using gigaseconds  = impl::swap_kind_prefix<seconds, impl::prefix::giga>;
using teraseconds  = impl::swap_kind_prefix<seconds, impl::prefix::tera>;
using petaseconds  = impl::swap_kind_prefix<seconds, impl::prefix::peta>;
using exaseconds   = impl::swap_kind_prefix<seconds, impl::prefix::exa>;

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

using seconds = impl::magnitude<kind::seconds, double>;

using attoseconds  = impl::magnitude<kind::attoseconds, double>;
using femtoseconds = impl::magnitude<kind::femtoseconds, double>;
using picoseconds  = impl::magnitude<kind::picoseconds, double>;
using nanoseconds  = impl::magnitude<kind::nanoseconds, double>;
using microseconds = impl::magnitude<kind::microseconds, double>;
using milliseconds = impl::magnitude<kind::milliseconds, double>;
using centiseconds = impl::magnitude<kind::centiseconds, double>;
using deciseconds  = impl::magnitude<kind::deciseconds, double>;
using noneseconds  = impl::magnitude<kind::noneseconds, double>;
using decaseconds  = impl::magnitude<kind::decaseconds, double>;
using hectoseconds = impl::magnitude<kind::hectoseconds, double>;
using kiloseconds  = impl::magnitude<kind::kiloseconds, double>;
using megaseconds  = impl::magnitude<kind::megaseconds, double>;
using gigaseconds  = impl::magnitude<kind::gigaseconds, double>;
using teraseconds  = impl::magnitude<kind::teraseconds, double>;
using petaseconds  = impl::magnitude<kind::petaseconds, double>;
using exaseconds   = impl::magnitude<kind::exaseconds, double>;

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

