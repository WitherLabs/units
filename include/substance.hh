// vim: set ft=cpp:

#pragma once

#include <mooncat/units/impl/prefixes>
#include <mooncat/units/impl/unit_container>

namespace lmc::units::substance
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<0>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<1>>;

template <impl::cnt::cpt::unit_container container>
using is_substance_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_substance_unit_v = is_substance_unit<container>::value;

using moles = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(moles)

} // namespace lmc::units::substance

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(substance, moles)
} // namespace ilmc
