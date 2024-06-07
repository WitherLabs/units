#pragma once

#include "current.hh"
#include "magnetic_flux.hh"

namespace lmc::units::inductance
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
using is_inductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_inductance_unit_v = is_inductance_unit<container>::value;

using henrys = impl::cnt::unit_container<impl::def::definition_divide<
    magnetic_flux::webers::definition,
    current::amperes::definition>>;

} // namespace lmc::units::inductance
