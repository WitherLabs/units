#pragma once

#include "force.hh"

namespace lmc::units::energy
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
using is_energy_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_energy_unit_v = is_energy_unit<container>::value;

using joules = impl::cnt::unit_container<impl::def::definition_multiply<
    force::newtons::definition,
    length::meters::definition>>;

ADD_PREFIXES_TO_CONTAINER(joules)

using foot_pound_force = impl::abbr::
    derive<std::ratio_add<std::ratio<1>, std::ratio<1779, 5000>>, joules>;

using horsepower_hour = impl::abbr::
    derive<std::ratio_add<std::ratio<2>, std::ratio<1369, 2000>>, megajoules>;

using kilowatt_hour = impl::abbr::derive<std::ratio<36, 10>, megajoules>;
using us_therms     = impl::abbr::derive<std::ratio<10548, 100>, megajoules>;

using calories_th   = impl::abbr::derive<std::ratio<4184, 1000>, joules>;
using calories_4    = impl::abbr::derive<std::ratio<4204, 1000>, joules>;
using calories_15   = impl::abbr::derive<std::ratio<41855, 10000>, joules>;
using calories_20   = impl::abbr::derive<std::ratio<4182, 1000>, joules>;
using calories_mean = impl::abbr::derive<std::ratio<4190, 1000>, joules>;
using calories_it   = impl::abbr::derive<std::ratio<41868, 10000>, joules>;

using electronvolts
    = impl::abbr::derive<std::ratio<160218, 1000000>, attojoules>;

using ton_of_tnt = impl::abbr::derive<std::ratio<4184>, joules>;

} // namespace lmc::units::energy
