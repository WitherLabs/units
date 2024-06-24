// vim: set ft=cpp:

#pragma once

#include <mooncat/units/resistance>

namespace lmc::units::conductance
{
using siemens = impl::cnt::unit_container<
    impl::def::definition_reciprocate<resistance::ohms::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(siemens)

using dimension = siemens::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_conductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_conductance_unit_v = is_conductance_unit<container>::value;

} // namespace lmc::units::conductance

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(conductance, siemens)
} // namespace ilmc
