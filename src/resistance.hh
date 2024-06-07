#pragma once

#include "voltage.hh"

namespace lmc::units::resistance
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
using is_resistance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_resistance_unit_v = is_resistance_unit<container>::value;

using ohms = impl::cnt::unit_container<impl::def::definition_divide<
    voltage::volts::definition,
    current::amperes::definition>>;

} // namespace lmc::units::resistance
