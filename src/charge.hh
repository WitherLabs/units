#pragma once

#include "current.hh"
#include "time.hh"

namespace lmc::units::charge
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
using is_charge_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_charge_unit_v = is_charge_unit<container>::value;

using coulombs = impl::cnt::unit_container<impl::def::definition_multiply<
    current::amperes::definition,
    time::seconds::definition>>;

} // namespace lmc::units::charge
