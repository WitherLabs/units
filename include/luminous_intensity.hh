#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dim
{

using luminous_intensity = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<1>  // luminous intensity
    >;

} // namespace dim

namespace kind
{

using candelas = impl::basic_kind<dim::luminous_intensity>;

using attocandelas  = impl::swap_kind_prefix<candelas, impl::prefix::atto>;
using femtocandelas = impl::swap_kind_prefix<candelas, impl::prefix::femto>;
using picocandelas  = impl::swap_kind_prefix<candelas, impl::prefix::pico>;
using nanocandelas  = impl::swap_kind_prefix<candelas, impl::prefix::nano>;
using microcandelas = impl::swap_kind_prefix<candelas, impl::prefix::micro>;
using millicandelas = impl::swap_kind_prefix<candelas, impl::prefix::milli>;
using centicandelas = impl::swap_kind_prefix<candelas, impl::prefix::centi>;
using decicandelas  = impl::swap_kind_prefix<candelas, impl::prefix::deci>;
using nonecandelas  = impl::swap_kind_prefix<candelas, impl::prefix::none>;
using decacandelas  = impl::swap_kind_prefix<candelas, impl::prefix::deca>;
using hectocandelas = impl::swap_kind_prefix<candelas, impl::prefix::hecto>;
using kilocandelas  = impl::swap_kind_prefix<candelas, impl::prefix::kilo>;
using megacandelas  = impl::swap_kind_prefix<candelas, impl::prefix::mega>;
using gigacandelas  = impl::swap_kind_prefix<candelas, impl::prefix::giga>;
using teracandelas  = impl::swap_kind_prefix<candelas, impl::prefix::tera>;
using petacandelas  = impl::swap_kind_prefix<candelas, impl::prefix::peta>;
using exacandelas   = impl::swap_kind_prefix<candelas, impl::prefix::exa>;

} // namespace kind

using candelas = impl::magnitude<kind::candelas, double>;

using attocandelas  = impl::magnitude<kind::attocandelas, double>;
using femtocandelas = impl::magnitude<kind::femtocandelas, double>;
using picocandelas  = impl::magnitude<kind::picocandelas, double>;
using nanocandelas  = impl::magnitude<kind::nanocandelas, double>;
using microcandelas = impl::magnitude<kind::microcandelas, double>;
using millicandelas = impl::magnitude<kind::millicandelas, double>;
using centicandelas = impl::magnitude<kind::centicandelas, double>;
using decicandelas  = impl::magnitude<kind::decicandelas, double>;
using nonecandelas  = impl::magnitude<kind::nonecandelas, double>;
using decacandelas  = impl::magnitude<kind::decacandelas, double>;
using hectocandelas = impl::magnitude<kind::hectocandelas, double>;
using kilocandelas  = impl::magnitude<kind::kilocandelas, double>;
using megacandelas  = impl::magnitude<kind::megacandelas, double>;
using gigacandelas  = impl::magnitude<kind::gigacandelas, double>;
using teracandelas  = impl::magnitude<kind::teracandelas, double>;
using petacandelas  = impl::magnitude<kind::petacandelas, double>;
using exacandelas   = impl::magnitude<kind::exacandelas, double>;

} // namespace units

