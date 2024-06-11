#pragma once

#include "resistance.hh"

namespace lmc::units::conductance
{
using siemens = impl::cnt::unit_container<
    impl::def::definition_reciprocate<resistance::ohms::definition>>;
ADD_PREFIXES_TO_CONTAINER(siemens)

using dimension = siemens::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_conductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_conductance_unit_v = is_conductance_unit<container>::value;

} // namespace lmc::units::conductance
