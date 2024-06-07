#pragma once

#include "substance.hh"
#include "time.hh"

namespace lmc::units::catalytic_activity
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
using is_catalytic_activity_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_catalytic_activity_unit_v
    = is_catalytic_activity_unit<container>::value;

using katals = impl::cnt::unit_container<impl::def::definition_divide<
    substance::moles::definition,
    time::seconds::definition>>;

} // namespace lmc::units::catalytic_activity
