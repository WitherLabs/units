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
using metres = impl::kind<
    length_dimension,
    impl::prefix::none,
    impl::ratio::base,
    impl::delta::none>;
using meters = metres;

using feet           = impl::derived_kind<meters, std::ratio<381, 1250>>::value;
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
using fathoms        = impl::derived_kind<meters, std::ratio<463, 250>>::value;
using cables         = impl::derived_kind<fathoms, std::ratio<100>>::value;
using nautical_miles = impl::derived_kind<cables, std::ratio<10>>::value;
using links          = impl::derived_kind<feet, std::ratio<66, 100>>::value;
using rods           = impl::derived_kind<links, std::ratio<25>>::value;

} // namespace kind

/// The meter is the base unit of length in the International System of Units.
/// It is defined as the distance travelled by light in `1 / 299792458` seconds
/// (in a vaccuum).
using metres = impl::magnitude<kind::metres, double>;
using meters = metres;

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

