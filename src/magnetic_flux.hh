#pragma once

#include "time.hh"
#include "voltage.hh"

namespace lmc::units::magnetic_flux
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<1>,
    impl::dim::current<1>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_magnetic_flux_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_magnetic_flux_unit_v
    = is_magnetic_flux_unit<container>::value;

using webers = impl::cnt::unit_container<impl::def::definition_multiply<
    voltage::volts::definition,
    time::seconds::definition>>;

} // namespace lmc::units::magnetic_flux
