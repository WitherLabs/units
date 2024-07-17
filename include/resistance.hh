// vim: set ft=cpp:

#pragma once

#include <mooncat/units/voltage>

namespace lmc::units::resistance
{

using ohms = impl::cnt::unit_container<impl::def::definition_divide<
    voltage::volts::definition,
    current::amperes::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(ohms)

using dimension = ohms::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_resistance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_resistance_unit_v = is_resistance_unit<container>::value;

} // namespace lmc::units::resistance

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(resistance, ohms)
} // namespace ilmc

