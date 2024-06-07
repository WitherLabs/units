#pragma once

#include "energy.hh"

namespace lmc::units::dose
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
using is_dose_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_dose_unit_v = is_dose_unit<container>::value;

namespace absorbed
{
using grays = impl::cnt::unit_container<impl::def::definition_divide<
    impl::def::definition_squared<energy::joules::definition>,
    impl::def::definition_squared<mass::kilograms::definition>>>;

} // namespace absorbed

namespace equivalent
{
using sieverts = impl::cnt::unit_container<impl::def::definition_divide<
    impl::def::definition_squared<energy::joules::definition>,
    impl::def::definition_squared<mass::kilograms::definition>>>;

} // namespace equivalent

} // namespace lmc::units::dose
