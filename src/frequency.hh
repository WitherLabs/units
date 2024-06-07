#pragma once

#include "time.hh"

namespace lmc::units::frequency
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<-1>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_frequency_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_frequency_unit_v = is_frequency_unit<container>::value;

using hertz                        = impl::cnt::unit_container<
    impl::def::definition_reciprocate<time::seconds::definition>>;

} // namespace lmc::units::frequency

