#pragma once

#include "length.hh"
#include "time.hh"

namespace lmc::units::velocity
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<1>,
    impl::dim::mass<0>,
    impl::dim::time<-1>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_velocity_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_velocity_unit_v = is_velocity_unit<container>::value;

using meters_per_second
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::meters::definition,
        time::seconds::definition>>;

using kilometers_per_hour
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::kilometers::definition,
        time::hours::definition>>;

using miles_per_hour = impl::cnt::unit_container<impl::def::definition_divide<
    length::miles::definition,
    time::hours::definition>>;

using inches_per_second
    = impl::cnt::unit_container<impl::def::definition_divide<
        length::inches::definition,
        time::seconds::definition>>;

using feet_per_second = impl::cnt::unit_container<impl::def::definition_divide<
    length::feet::definition,
    time::seconds::definition>>;

using knot            = impl::cnt::unit_container<impl::def::definition_divide<
    length::nautical_miles::definition,
    time::hours::definition>>;

} // namespace lmc::units::velocity

