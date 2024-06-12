#pragma once

#include <mooncat/units/time>
#include <mooncat/units/voltage>

namespace lmc::units::magnetic_flux
{
using webers = impl::cnt::unit_container<impl::def::definition_multiply<
    voltage::volts::definition,
    time::seconds::definition>>;
ADD_PREFIXES_TO_CONTAINER(webers)

using dimension = webers::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_magnetic_flux_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_magnetic_flux_unit_v
    = is_magnetic_flux_unit<container>::value;

} // namespace lmc::units::magnetic_flux
