#pragma once

#include <wither/units/units.hh>

// clang-format off

namespace units
{

namespace dim
{

using mass = impl::dimension<
    std::ratio<0>, // length
    std::ratio<1>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

} // namespace dim

namespace kind
{

using grams      = impl::basic_kind<dim::mass>;  
using attograms  = impl::swap_kind_prefix<grams, impl::prefix::atto>;
using femtograms = impl::swap_kind_prefix<grams, impl::prefix::femto>;
using picograms  = impl::swap_kind_prefix<grams, impl::prefix::pico>;
using nanograms  = impl::swap_kind_prefix<grams, impl::prefix::nano>;
using micrograms = impl::swap_kind_prefix<grams, impl::prefix::micro>;
using milligrams = impl::swap_kind_prefix<grams, impl::prefix::milli>;
using centigrams = impl::swap_kind_prefix<grams, impl::prefix::centi>;
using decigrams  = impl::swap_kind_prefix<grams, impl::prefix::deci>;
using nonegrams  = impl::swap_kind_prefix<grams, impl::prefix::none>;
using decagrams  = impl::swap_kind_prefix<grams, impl::prefix::deca>;
using hectograms = impl::swap_kind_prefix<grams, impl::prefix::hecto>;
using kilograms  = impl::swap_kind_prefix<grams, impl::prefix::kilo>;
using megagrams  = impl::swap_kind_prefix<grams, impl::prefix::mega>;
using gigagrams  = impl::swap_kind_prefix<grams, impl::prefix::giga>;
using teragrams  = impl::swap_kind_prefix<grams, impl::prefix::tera>;
using petagrams  = impl::swap_kind_prefix<grams, impl::prefix::peta>;
using exagrams   = impl::swap_kind_prefix<grams, impl::prefix::exa>;

using pounds         = impl::derived_kind<grams,  std::ratio<45359237, 100000>>;
using grains         = impl::derived_kind<pounds, std::ratio<1,        7000>>;
using drachms        = impl::derived_kind<pounds, std::ratio<1,        256>>;
using ounces         = impl::derived_kind<pounds, std::ratio<1,        16>>;
using stones         = impl::derived_kind<pounds, std::ratio<14,       1>>;
using quarters       = impl::derived_kind<pounds, std::ratio<28,       1>>;
using hundredweights = impl::derived_kind<pounds, std::ratio<112,      1>>;
using tons           = impl::derived_kind<pounds, std::ratio<2240,     1>>;

} // namespace kind

using attograms      = impl::magnitude<kind::attograms,      double>;
using femtograms     = impl::magnitude<kind::femtograms,     double>;
using picograms      = impl::magnitude<kind::picograms,      double>;
using nanograms      = impl::magnitude<kind::nanograms,      double>;
using micrograms     = impl::magnitude<kind::micrograms,     double>;
using milligrams     = impl::magnitude<kind::milligrams,     double>;
using centigrams     = impl::magnitude<kind::centigrams,     double>;
using decigrams      = impl::magnitude<kind::decigrams,      double>;
using nonegrams      = impl::magnitude<kind::nonegrams,      double>;
using decagrams      = impl::magnitude<kind::decagrams,      double>;
using hectograms     = impl::magnitude<kind::hectograms,     double>;
using kilograms      = impl::magnitude<kind::kilograms,      double>;
using megagrams      = impl::magnitude<kind::megagrams,      double>;
using gigagrams      = impl::magnitude<kind::gigagrams,      double>;
using teragrams      = impl::magnitude<kind::teragrams,      double>;
using petagrams      = impl::magnitude<kind::petagrams,      double>;
using exagrams       = impl::magnitude<kind::exagrams,       double>;
using grams          = impl::magnitude<kind::grams,          double>;
using pounds         = impl::magnitude<kind::pounds,         double>;
using grains         = impl::magnitude<kind::grains,         double>;
using drachms        = impl::magnitude<kind::drachms,        double>;
using ounces         = impl::magnitude<kind::ounces,         double>;
using stones         = impl::magnitude<kind::stones,         double>;
using quarters       = impl::magnitude<kind::quarters,       double>;
using hundredweights = impl::magnitude<kind::hundredweights, double>;
using tons           = impl::magnitude<kind::tons,           double>;

} // namespace units

// clang-format on

