#pragma once

#include "prefixes.hh"
#include "unit_container.hh"

namespace lmc::units::length
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<1>,
    impl::dim::mass<0>,
    impl::dim::time<0>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_length_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_length_unit_v = is_length_unit<container>::value;

using meters         = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

using feet           = impl::abbr::derive<std::ratio<381, 1250>, meters>;
using twips          = impl::abbr::derive<std::ratio<1, 17280>, feet>;
using thous          = impl::abbr::derive<std::ratio<1, 12000>, feet>;
using barleycorns    = impl::abbr::derive<std::ratio<1, 36>, feet>;
using inches         = impl::abbr::derive<std::ratio<3>, barleycorns>;
using hands          = impl::abbr::derive<std::ratio<4>, inches>;
using yards          = impl::abbr::derive<std::ratio<3>, feet>;
using chains         = impl::abbr::derive<std::ratio<22>, yards>;
using furlongs       = impl::abbr::derive<std::ratio<10>, chains>;
using miles          = impl::abbr::derive<std::ratio<8>, furlongs>;
using leagues        = impl::abbr::derive<std::ratio<3>, miles>;
using fathoms        = impl::abbr::derive<std::ratio<463, 250>, meters>;
using cables         = impl::abbr::derive<std::ratio<100>, fathoms>;
using nautical_miles = impl::abbr::derive<std::ratio<10>, cables>;
using links          = impl::abbr::derive<std::ratio<66, 100>, feet>;
using rods           = impl::abbr::derive<std::ratio<25>, links>;

ADD_PREFIXES_TO_CONTAINER(meters)

} // namespace lmc::units::length

