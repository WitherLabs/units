#pragma once

#include <wither/units/current.hh>
#include <wither/units/time.hh>

namespace units
{

namespace kind
{

// clang-format off

using coulombs      = impl::multiply_kinds<amperes, seconds>;
using attocoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::atto>;
using femtocoulombs = impl::swap_kind_prefix<coulombs, impl::prefix::femto>;
using picocoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::pico>;
using nanocoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::nano>;
using microcoulombs = impl::swap_kind_prefix<coulombs, impl::prefix::micro>;
using millicoulombs = impl::swap_kind_prefix<coulombs, impl::prefix::milli>;
using centicoulombs = impl::swap_kind_prefix<coulombs, impl::prefix::centi>;
using decicoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::deci>;
using nonecoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::none>;
using decacoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::deca>;
using hectocoulombs = impl::swap_kind_prefix<coulombs, impl::prefix::hecto>;
using kilocoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::kilo>;
using megacoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::mega>;
using gigacoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::giga>;
using teracoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::tera>;
using petacoulombs  = impl::swap_kind_prefix<coulombs, impl::prefix::peta>;
using exacoulombs   = impl::swap_kind_prefix<coulombs, impl::prefix::exa>;

// clang-format on

} // namespace kind

// clang-format off

using coulombs      = impl::magnitude<kind::coulombs, double>;
using attocoulombs  = impl::magnitude<kind::attocoulombs, double>;
using femtocoulombs = impl::magnitude<kind::femtocoulombs, double>;
using picocoulombs  = impl::magnitude<kind::picocoulombs, double>;
using nanocoulombs  = impl::magnitude<kind::nanocoulombs, double>;
using microcoulombs = impl::magnitude<kind::microcoulombs, double>;
using millicoulombs = impl::magnitude<kind::millicoulombs, double>;
using centicoulombs = impl::magnitude<kind::centicoulombs, double>;
using decicoulombs  = impl::magnitude<kind::decicoulombs, double>;
using nonecoulombs  = impl::magnitude<kind::nonecoulombs, double>;
using decacoulombs  = impl::magnitude<kind::decacoulombs, double>;
using hectocoulombs = impl::magnitude<kind::hectocoulombs, double>;
using kilocoulombs  = impl::magnitude<kind::kilocoulombs, double>;
using megacoulombs  = impl::magnitude<kind::megacoulombs, double>;
using gigacoulombs  = impl::magnitude<kind::gigacoulombs, double>;
using teracoulombs  = impl::magnitude<kind::teracoulombs, double>;
using petacoulombs  = impl::magnitude<kind::petacoulombs, double>;
using exacoulombs   = impl::magnitude<kind::exacoulombs, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

