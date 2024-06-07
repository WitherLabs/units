#pragma once

#include "current.hh"
#include "power.hh"

namespace lmc::units::voltage
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
using is_voltage_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_voltage_unit_v = is_voltage_unit<container>::value;

using volts = impl::cnt::unit_container<impl::def::definition_divide<
    power::watts::definition,
    current::amperes::definition>>;

} // namespace lmc::units::voltage
