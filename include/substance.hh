#pragma once

#include <wither/units/units.hh>

namespace units
{

namespace dim
{

using substance = impl::dimension<
    std::ratio<0>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<1>, // substance
    std::ratio<0>  // luminous intensity
    >;

} // namespace dim

namespace kind
{

using moles = impl::basic_kind<dim::substance>;

using attomoles  = impl::swap_kind_prefix<moles, impl::prefix::atto>;
using femtomoles = impl::swap_kind_prefix<moles, impl::prefix::femto>;
using picomoles  = impl::swap_kind_prefix<moles, impl::prefix::pico>;
using nanomoles  = impl::swap_kind_prefix<moles, impl::prefix::nano>;
using micromoles = impl::swap_kind_prefix<moles, impl::prefix::micro>;
using millimoles = impl::swap_kind_prefix<moles, impl::prefix::milli>;
using centimoles = impl::swap_kind_prefix<moles, impl::prefix::centi>;
using decimoles  = impl::swap_kind_prefix<moles, impl::prefix::deci>;
using nonemoles  = impl::swap_kind_prefix<moles, impl::prefix::none>;
using decamoles  = impl::swap_kind_prefix<moles, impl::prefix::deca>;
using hectomoles = impl::swap_kind_prefix<moles, impl::prefix::hecto>;
using kilomoles  = impl::swap_kind_prefix<moles, impl::prefix::kilo>;
using megamoles  = impl::swap_kind_prefix<moles, impl::prefix::mega>;
using gigamoles  = impl::swap_kind_prefix<moles, impl::prefix::giga>;
using teramoles  = impl::swap_kind_prefix<moles, impl::prefix::tera>;
using petamoles  = impl::swap_kind_prefix<moles, impl::prefix::peta>;
using examoles   = impl::swap_kind_prefix<moles, impl::prefix::exa>;

} // namespace kind

using moles = impl::magnitude<kind::moles, double>;

using attomoles  = impl::magnitude<kind::attomoles, double>;
using femtomoles = impl::magnitude<kind::femtomoles, double>;
using picomoles  = impl::magnitude<kind::picomoles, double>;
using nanomoles  = impl::magnitude<kind::nanomoles, double>;
using micromoles = impl::magnitude<kind::micromoles, double>;
using millimoles = impl::magnitude<kind::millimoles, double>;
using centimoles = impl::magnitude<kind::centimoles, double>;
using decimoles  = impl::magnitude<kind::decimoles, double>;
using nonemoles  = impl::magnitude<kind::nonemoles, double>;
using decamoles  = impl::magnitude<kind::decamoles, double>;
using hectomoles = impl::magnitude<kind::hectomoles, double>;
using kilomoles  = impl::magnitude<kind::kilomoles, double>;
using megamoles  = impl::magnitude<kind::megamoles, double>;
using gigamoles  = impl::magnitude<kind::gigamoles, double>;
using teramoles  = impl::magnitude<kind::teramoles, double>;
using petamoles  = impl::magnitude<kind::petamoles, double>;
using examoles   = impl::magnitude<kind::examoles, double>;

} // namespace units

