#pragma once

#include <mooncat/units/impl/prefixes.hh>
#include <mooncat/units/impl/unit_container.hh>

namespace lmc::units::mass
{

using dimension = impl::dim::dimensional_vector<
    impl::dim::length<0>,
    impl::dim::mass<1>,
    impl::dim::time<0>,
    impl::dim::current<0>,
    impl::dim::temperature<0>,
    impl::dim::luminosity<0>,
    impl::dim::substance<0>>;

template <impl::cnt::cpt::unit_container container>
using is_mass_unit
    = dimension::equals<typename container::definition::dimension>;

template <impl::cnt::cpt::unit_container container>
constexpr bool is_mass_unit_v = is_mass_unit<container>::value;

using grams          = impl::cnt::unit_container<impl::def::unit_definition<
    dimension,
    impl::cmp::base_unit_prefix,
    impl::cmp::base_unit_ratio,
    impl::cmp::base_unit_delta>>;

using pounds         = impl::abbr::derive<std::ratio<45359237, 100000>, grams>;
using grains         = impl::abbr::derive<std::ratio<1, 7000>, pounds>;
using drachms        = impl::abbr::derive<std::ratio<1, 256>, pounds>;
using ounces         = impl::abbr::derive<std::ratio<1, 16>, pounds>;
using stones         = impl::abbr::derive<std::ratio<14>, pounds>;
using quarters       = impl::abbr::derive<std::ratio<28>, pounds>;
using hundredweights = impl::abbr::derive<std::ratio<112>, pounds>;
using tons           = impl::abbr::derive<std::ratio<2240>, pounds>;

ADD_PREFIXES_TO_CONTAINER(grams)

} // namespace lmc::units::mass
