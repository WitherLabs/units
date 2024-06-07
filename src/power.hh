#pragma once

#include "energy.hh"

namespace lmc::units::power
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<1>,
    impl::dim::mass<-1>,
    impl::dim::time<-2>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_power_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_power_unit_v = is_power_unit<container>::value;

using watts      = impl::cnt::unit_container<impl::def::definition_divide<
    energy::joules::definition,
    time::seconds::definition>>;

using horsepower = impl::abbr::derive<std::ratio<7457, 10>, watts>;

} // namespace lmc::units::power
