#pragma once

#include "magnetic_flux.hh"

namespace lmc::units::inductance
{
using henrys = impl::cnt::unit_container<impl::def::definition_divide<
    magnetic_flux::webers::definition,
    current::amperes::definition>>;
ADD_PREFIXES_TO_CONTAINER(henrys)

using dimension = henrys::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_inductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_inductance_unit_v = is_inductance_unit<container>::value;

} // namespace lmc::units::inductance
