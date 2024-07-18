#pragma once

#include <wither/units/units.hh>

namespace units
{

using length_dimension = impl::dimension<
    std::ratio<1>, // length
    std::ratio<0>, // mass
    std::ratio<0>, // time
    std::ratio<0>, // current
    std::ratio<0>, // temperature
    std::ratio<0>, // substance
    std::ratio<0>  // luminous intensity
    >;

namespace kind
{

using metres = impl::basic_kind<length_dimension>;

using attometres  = impl::swap_kind_prefix<metres, impl::prefix::atto>;
using femtometres = impl::swap_kind_prefix<metres, impl::prefix::femto>;
using picometres  = impl::swap_kind_prefix<metres, impl::prefix::pico>;
using nanometres  = impl::swap_kind_prefix<metres, impl::prefix::nano>;
using micrometres = impl::swap_kind_prefix<metres, impl::prefix::micro>;
using millimetres = impl::swap_kind_prefix<metres, impl::prefix::milli>;
using centimetres = impl::swap_kind_prefix<metres, impl::prefix::centi>;
using decimetres  = impl::swap_kind_prefix<metres, impl::prefix::deci>;
using nonemetres  = impl::swap_kind_prefix<metres, impl::prefix::none>;
using decametres  = impl::swap_kind_prefix<metres, impl::prefix::deca>;
using hectometres = impl::swap_kind_prefix<metres, impl::prefix::hecto>;
using kilometres  = impl::swap_kind_prefix<metres, impl::prefix::kilo>;
using megametres  = impl::swap_kind_prefix<metres, impl::prefix::mega>;
using gigametres  = impl::swap_kind_prefix<metres, impl::prefix::giga>;
using terametres  = impl::swap_kind_prefix<metres, impl::prefix::tera>;
using petametres  = impl::swap_kind_prefix<metres, impl::prefix::peta>;
using exametres   = impl::swap_kind_prefix<metres, impl::prefix::exa>;

using feet           = impl::derived_kind<metres, std::ratio<381, 1250>>::value;
using twips          = impl::derived_kind<feet, std::ratio<1, 17280>>::value;
using thous          = impl::derived_kind<feet, std::ratio<1, 12000>>::value;
using barleycorns    = impl::derived_kind<feet, std::ratio<1, 36>>::value;
using inches         = impl::derived_kind<barleycorns, std::ratio<3>>::value;
using hands          = impl::derived_kind<inches, std::ratio<4>>::value;
using yards          = impl::derived_kind<feet, std::ratio<3>>::value;
using chains         = impl::derived_kind<yards, std::ratio<22>>::value;
using furlongs       = impl::derived_kind<chains, std::ratio<10>>::value;
using miles          = impl::derived_kind<furlongs, std::ratio<8>>::value;
using leagues        = impl::derived_kind<miles, std::ratio<3>>::value;
using fathoms        = impl::derived_kind<metres, std::ratio<463, 250>>::value;
using cables         = impl::derived_kind<fathoms, std::ratio<100>>::value;
using nautical_miles = impl::derived_kind<cables, std::ratio<10>>::value;
using links          = impl::derived_kind<feet, std::ratio<66, 100>>::value;
using rods           = impl::derived_kind<links, std::ratio<25>>::value;

} // namespace kind

using metres = impl::magnitude<kind::metres, double>;

using attometres  = impl::magnitude<kind::attometres, double>;
using femtometres = impl::magnitude<kind::femtometres, double>;
using picometres  = impl::magnitude<kind::picometres, double>;
using nanometres  = impl::magnitude<kind::nanometres, double>;
using micrometres = impl::magnitude<kind::micrometres, double>;
using millimetres = impl::magnitude<kind::millimetres, double>;
using centimetres = impl::magnitude<kind::centimetres, double>;
using decimetres  = impl::magnitude<kind::decimetres, double>;
using nonemetres  = impl::magnitude<kind::nonemetres, double>;
using decametres  = impl::magnitude<kind::decametres, double>;
using hectometres = impl::magnitude<kind::hectometres, double>;
using kilometres  = impl::magnitude<kind::kilometres, double>;
using megametres  = impl::magnitude<kind::megametres, double>;
using gigametres  = impl::magnitude<kind::gigametres, double>;
using terametres  = impl::magnitude<kind::terametres, double>;
using petametres  = impl::magnitude<kind::petametres, double>;
using exametres   = impl::magnitude<kind::exametres, double>;

using feet           = impl::magnitude<kind::feet, double>;
using twips          = impl::magnitude<kind::twips, double>;
using thous          = impl::magnitude<kind::thous, double>;
using barleycorns    = impl::magnitude<kind::barleycorns, double>;
using inches         = impl::magnitude<kind::inches, double>;
using hands          = impl::magnitude<kind::hands, double>;
using yards          = impl::magnitude<kind::yards, double>;
using chains         = impl::magnitude<kind::chains, double>;
using furlongs       = impl::magnitude<kind::furlongs, double>;
using miles          = impl::magnitude<kind::miles, double>;
using leagues        = impl::magnitude<kind::leagues, double>;
using fathoms        = impl::magnitude<kind::fathoms, double>;
using cables         = impl::magnitude<kind::cables, double>;
using nautical_miles = impl::magnitude<kind::nautical_miles, double>;
using links          = impl::magnitude<kind::links, double>;
using rods           = impl::magnitude<kind::rods, double>;

} // namespace units

