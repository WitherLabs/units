#pragma once

#include "charge.hh"
#include "voltage.hh"

namespace lmc::units::capacitance
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
using is_capacitance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_capacitance_unit_v = is_capacitance_unit<container>::value;

using farads = impl::cnt::unit_container<impl::def::definition_divide<
    charge::coulombs::definition,
    voltage::volts::definition>>;

} // namespace lmc::units::capacitance
