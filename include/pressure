// vim: set ft=cpp:

#pragma once

#include <mooncat/units/force>

namespace lmc::units::pressure
{
using pascals = impl::cnt::unit_container<impl::def::definition_divide<
    force::newtons::definition,
    impl::def::definition_squared<length::meters::definition>>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(pascals)

using dimension = pascals::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_pressure_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_pressure_unit_v = is_pressure_unit<container>::value;

using bars = impl::abbr::derive<std::ratio<100000>, pascals>;

using technical_atmospheres
    = impl::abbr::derive<std::ratio<980665, 10>, pascals>;

using atmospheres = impl::abbr::derive<std::ratio<101325>, pascals>;

using torrs = impl::abbr::derive<std::ratio<1, 760>, atmospheres>;

using pounds_per_square_inch = impl::abbr::derive<
    std::ratio_add<std::ratio<6894>, std::ratio<47330823, 62500000>>,
    pascals>;

} // namespace lmc::units::pressure

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(pressure, pascals)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(pressure, bars)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(pressure, technical_atmospheres)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(pressure, atmospheres)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(pressure, torrs)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(pressure, pounds_per_square_inch)
} // namespace ilmc
