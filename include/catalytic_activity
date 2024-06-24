// vim: set ft=cpp:

#pragma once

#include <mooncat/units/substance>
#include <mooncat/units/time>

namespace lmc::units::catalytic_activity
{
using katals = impl::cnt::unit_container<impl::def::definition_divide<
    substance::moles::definition,
    time::seconds::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(katals)

using dimension = katals::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_catalytic_activity_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_catalytic_activity_unit_v
    = is_catalytic_activity_unit<container>::value;

} // namespace lmc::units::catalytic_activity

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(catalytic_activity, katals)
} // namespace ilmc
