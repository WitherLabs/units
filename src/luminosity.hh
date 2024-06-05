#pragma once

#include "prefixes.hh"
#include "unit_container.hh"

namespace lmc::units::luminosity
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<0>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<1>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_luminosity_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_luminosity_unit_v = is_luminosity_unit<container>::value;

using candelas = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

ADD_PREFIXES_TO_CONTAINER(candelas)

} // namespace lmc::units::luminosity
