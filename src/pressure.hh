#pragma once

#include "force.hh"
#include "length.hh"
#include "unit_container.hh"
#include "unit_definition.hh"

namespace lmc::units::pressure
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
using is_pressure_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_pressure_unit_v = is_pressure_unit<container>::value;

using pascals = impl::cnt::unit_container<impl::def::definition_divide<
    force::newtons::definition,
    impl::def::definition_squared<length::meters::definition>>>;

using bars    = impl::abbr::derive<std::ratio<100000>, pascals>;

using technical_atmospheres
    = impl::abbr::derive<std::ratio<980665, 10>, pascals>;

using atmospheres = impl::abbr::derive<std::ratio<101325>, pascals>;

using torrs       = impl::abbr::derive<std::ratio<1, 760>, atmospheres>;

using pounds_per_square_inch = impl::abbr::derive<
    std::ratio_add<std::ratio<6894>, std::ratio<47330823, 62500000>>,
    pascals>;

} // namespace lmc::units::pressure

