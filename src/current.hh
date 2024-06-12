#pragma once

#include <mooncat/units/impl/prefixes.hh>
#include <mooncat/units/impl/unit_container.hh>

namespace lmc::units::current
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<0>,
    impl::dim::current<1>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_current_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_current_unit_v = is_current_unit<container>::value;

using amperes = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

ADD_PREFIXES_TO_CONTAINER(amperes)

} // namespace lmc::units::current
