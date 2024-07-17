// vim: set ft=cpp:

#pragma once

#include <mooncat/units/length>
#include <mooncat/units/mass>
#include <mooncat/units/time>

namespace lmc::units::force
{
using newtons = impl::cnt::unit_container<impl::def::definition_divide<
    impl::def::definition_multiply<
        mass::kilograms::definition,
        length::meters::definition>,
    impl::def::definition_squared<time::seconds::definition>>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(newtons)

using dimension = newtons::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_force_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_force_unit_v = is_force_unit<container>::value;

using kilopond = impl::abbr::
    derive<std::ratio_add<std::ratio<9>, std::ratio<16133, 20000>>, newtons>;

using pounds = impl::abbr::
    derive<std::ratio_add<std::ratio<4>, std::ratio<224111, 500000>>, newtons>;

using poundal
    = impl::abbr::derive<std::ratio<17281869297, 125000000000>, newtons>;

using dynes = impl::abbr::derive<std::ratio<1, 100000>, newtons>;

} // namespace lmc::units::force

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(force, newtons)
} // namespace ilmc
