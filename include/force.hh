#pragma once

#include "units.hh"
#include <wither/units/acceleration.hh>
#include <wither/units/mass.hh>

namespace units
{

namespace kind
{

using newtons  = impl::multiply_kinds<metres_per_second_squared, kilograms>;
using kilopond = impl::
    derived_kind<newtons, util::mixed_ratio<9, std::ratio<16133, 20000>>>;
using pounds_of_force = impl::
    derived_kind<newtons, util::mixed_ratio<4, std::ratio<224111, 500000>>>;
using poundals
    = impl::derived_kind<newtons, std::ratio<17281869297, 125000000000>>;
using dynes = impl::derived_kind<newtons, std::ratio<1, 100000>>;

} // namespace kind

using newtons         = impl::magnitude<kind::newtons, double>;
using kilopond        = impl::magnitude<kind::kilopond, double>;
using pounds_of_force = impl::magnitude<kind::pounds_of_force, double>;
using poundals        = impl::magnitude<kind::poundals, double>;
using dynes           = impl::magnitude<kind::dynes, double>;

namespace dim
{

} // namespace dim

} // namespace units

