#pragma once

#include "resistance.hh"

namespace lmc::units::conductance
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
using is_conductance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_conductance_unit_v = is_conductance_unit<container>::value;

using siemens                        = impl::cnt::unit_container<
    impl::def::definition_reciprocate<resistance::ohms::definition>>;

} // namespace lmc::units::conductance
