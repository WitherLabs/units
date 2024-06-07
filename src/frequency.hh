#pragma once

#include "time.hh"

namespace lmc::units::frequency
{
using hertz = impl::cnt::unit_container<
    impl::def::definition_reciprocate<time::seconds::definition>>;
ADD_PREFIXES_TO_CONTAINER(hertz)

using dimension = hertz::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_frequency_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_frequency_unit_v = is_frequency_unit<container>::value;

} // namespace lmc::units::frequency

