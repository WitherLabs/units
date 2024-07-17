// vim: set ft=cpp:

#pragma once

#include <mooncat/units/energy>

namespace lmc::units::power
{
using watts = impl::cnt::unit_container<impl::def::definition_divide<
    energy::joules::definition,
    time::seconds::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(watts)

using dimension = watts::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_power_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_power_unit_v = is_power_unit<container>::value;

using horsepower = impl::abbr::derive<std::ratio<7457, 10>, watts>;

} // namespace lmc::units::power

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(power, watts)
} // namespace ilmc
