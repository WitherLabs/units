// vim: set ft=cpp:

#pragma once

#include <mooncat/units/magnetic_flux>

namespace lmc::units::inductance
{
using henrys = impl::cnt::unit_container<impl::def::definition_divide<
    magnetic_flux::webers::definition,
    current::amperes::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(henrys)

using dimension = henrys::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_inductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_inductance_unit_v = is_inductance_unit<container>::value;

} // namespace lmc::units::inductance
  //

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(inductance, henrys)
} // namespace ilmc
