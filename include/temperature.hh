// vim: set ft=cpp:

#pragma once

#include <mooncat/units/impl/prefixes>
#include <mooncat/units/impl/unit_container>

namespace lmc::units::temperature
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<0>,
    impl::dim::current<0>,
    impl::dim::temperature<1>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_temperature_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_temperature_unit_v = is_temperature_unit<container>::value;

using kelvins = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

using celsius = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::def::derive_unit_ratio<std::ratio<1>, kelvins::definition>,
    impl::cmp::unit_delta<std::ratio<-27315, 100>>>>;

using fahrenheit = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::def::derive_unit_ratio<std::ratio<5, 9>, celsius::definition>,
    impl::def::derive_unit_delta<celsius::definition, std::ratio<160, 9>>>>;

LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(kelvins)

} // namespace lmc::units::temperature

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(temperature, kelvins)
} // namespace ilmc
