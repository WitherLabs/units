// vim: set ft=cpp:

#pragma once

#include <mooncat/units/energy>

namespace lmc::units::dose
{

namespace absorbed
{
using grays = impl::cnt::unit_container<impl::def::definition_divide<
    energy::joules::definition,
    mass::kilograms::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(grays)

} // namespace absorbed

namespace equivalent
{
using sieverts = impl::cnt::unit_container<impl::def::definition_divide<
    energy::joules::definition,
    mass::kilograms::definition>>;
LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(sieverts)

} // namespace equivalent

static_assert(absorbed::grays::definition::dimension::equals_v<
              equivalent::sieverts::definition::dimension>);

using dimension = absorbed::grays::definition::dimension;

template <impl::cnt::cpt::unit_container container>
using is_dose_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_dose_unit_v = is_dose_unit<container>::value;

} // namespace lmc::units::dose
  //

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(dose::absorbed, grays)
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(dose::equivalent, sieverts)
} // namespace ilmc
