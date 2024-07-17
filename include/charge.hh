// vim: set ft=cpp:

#pragma once

#include <mooncat/units/current>
#include <mooncat/units/time>

namespace lmc::units::charge
{
using coulombs = impl::cnt::unit_container<impl::def::definition_multiply<
    current::amperes::definition,
    time::seconds::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(coulombs)

using dimension = coulombs::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_charge_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_charge_unit_v = is_charge_unit<container>::value;

} // namespace lmc::units::charge

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(charge, coulombs)
} // namespace ilmc
