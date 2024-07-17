// vim: set ft=cpp:

#pragma once

#include <mooncat/units/impl/prefixes>
#include <mooncat/units/impl/unit_container>

namespace lmc::units::time
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<0>,
    impl::dim::time<1>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_time_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_time_unit_v = is_time_unit<container>::value;

using seconds = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

using minutes    = impl::abbr::derive<std::ratio<60>, seconds>;
using hours      = impl::abbr::derive<std::ratio<60>, minutes>;
using days       = impl::abbr::derive<std::ratio<24>, hours>;
using weeks      = impl::abbr::derive<std::ratio<7>, days>;
using months_28  = impl::abbr::derive<std::ratio<28>, days>;
using months_29  = impl::abbr::derive<std::ratio<29>, days>;
using months_30  = impl::abbr::derive<std::ratio<30>, days>;
using months_31  = impl::abbr::derive<std::ratio<31>, days>;
using years      = impl::abbr::derive<std::ratio<365>, days>;
using leap_years = impl::abbr::derive<std::ratio<366>, days>;
using decades    = impl::abbr::derive<std::ratio<10>, years>;
using centuries  = impl::abbr::derive<std::ratio<100>, years>;
using eons       = impl::abbr::derive<std::ratio<1000000000>, years>;

LMC_UNITS_ADD_PREFIXES_TO_CONTAINER(seconds)

} // namespace lmc::units::time

inline namespace ilmc
{
LMC_UNITS_CREATE_PREFIXED_UNIT_LITERAL_OPERATOR(time, seconds)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(time, minutes)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(time, hours)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(time, days)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(time, weeks)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(time, years)
} // namespace ilmc
