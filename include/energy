// vim: set ft=cpp:

#pragma once

#include <mooncat/units/force>

namespace lmc::units::energy
{
using joules = impl::cnt::unit_container<impl::def::definition_multiply<
    force::newtons::definition,
    length::meters::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(joules)

using dimension = joules::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_energy_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_energy_unit_v = is_energy_unit<container>::value;

using foot_pound_force = impl::abbr::
    derive<std::ratio_add<std::ratio<1>, std::ratio<1779, 5000>>, joules>;

using horsepower_hour = impl::abbr::
    derive<std::ratio_add<std::ratio<2>, std::ratio<1369, 2000>>, megajoules>;

using kilowatt_hour = impl::abbr::derive<std::ratio<36, 10>, megajoules>;
using us_therms     = impl::abbr::derive<std::ratio<10548, 100>, megajoules>;

using calories_th   = impl::abbr::derive<std::ratio<4184, 1000>, joules>;
using calories_4    = impl::abbr::derive<std::ratio<4204, 1000>, joules>;
using calories_15   = impl::abbr::derive<std::ratio<41855, 10000>, joules>;
using calories_20   = impl::abbr::derive<std::ratio<4182, 1000>, joules>;
using calories_mean = impl::abbr::derive<std::ratio<4190, 1000>, joules>;
using calories_it   = impl::abbr::derive<std::ratio<41868, 10000>, joules>;

using electronvolts
    = impl::abbr::derive<std::ratio<160218, 1000000>, attojoules>;

using ton_of_tnt = impl::abbr::derive<std::ratio<4184>, joules>;

} // namespace lmc::units::energy

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(energy, joules)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, foot_pound_force)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, horsepower_hour)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, kilowatt_hour)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, calories_it)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, electronvolts)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(energy, ton_of_tnt)
} // namespace ilmc
