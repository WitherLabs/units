// vim: set ft=cpp:

#pragma once

#include <mooncat/units/current>
#include <mooncat/units/power>

namespace lmc::units::voltage
{
using volts = impl::cnt::unit_container<impl::def::definition_divide<
    power::watts::definition,
    current::amperes::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(volts)

using dimension = volts::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_voltage_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_voltage_unit_v = is_voltage_unit<container>::value;

} // namespace lmc::units::voltage

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(voltage, volts)
} // namespace ilmc
