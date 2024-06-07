#pragma once

#include "length.hh"
#include "mass.hh"
#include "time.hh"
#include "unit_container.hh"

namespace lmc::units::force
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<1>,
    impl::dim::mass<1>,
    impl::dim::time<-2>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_force_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_force_unit_v = is_force_unit<container>::value;

using newtons  = impl::cnt::unit_container<impl::def::definition_divide<
    impl::def::definition_multiply<
        mass::kilograms::definition,
        length::meters::definition>,
    impl::def::definition_squared<time::seconds::definition>>>;

using kilopond = impl::abbr::
    derive<std::ratio_add<std::ratio<9>, std::ratio<16133, 20000>>, newtons>;

using pounds = impl::abbr::
    derive<std::ratio_add<std::ratio<4>, std::ratio<224111, 500000>>, newtons>;

using poundal
    = impl::abbr::derive<std::ratio<17281869297, 125000000000>, newtons>;

using dynes = impl::abbr::derive<std::ratio<1, 100000>, newtons>;

} // namespace lmc::units::force

