#pragma once

#include "unit_definition.hh"

#include <ratio>

namespace lmc::units::prefix
{
using atto  = impl::cmp::unit_prefix<std::atto>;
using femto = impl::cmp::unit_prefix<std::femto>;
using pico  = impl::cmp::unit_prefix<std::pico>;
using nano  = impl::cmp::unit_prefix<std::nano>;
using micro = impl::cmp::unit_prefix<std::micro>;
using milli = impl::cmp::unit_prefix<std::milli>;
using centi = impl::cmp::unit_prefix<std::centi>;
using deci  = impl::cmp::unit_prefix<std::deci>;
using none  = impl::cmp::unit_prefix<std::ratio<1, 1>>;
using deca  = impl::cmp::unit_prefix<std::deca>;
using hecto = impl::cmp::unit_prefix<std::hecto>;
using kilo  = impl::cmp::unit_prefix<std::kilo>;
using mega  = impl::cmp::unit_prefix<std::mega>;
using giga  = impl::cmp::unit_prefix<std::giga>;
using tera  = impl::cmp::unit_prefix<std::tera>;
using peta  = impl::cmp::unit_prefix<std::peta>;
using exa   = impl::cmp::unit_prefix<std::exa>;
} // namespace lmc::units::prefix

#define ADD_PREFIXES_TO_CONTAINER(name)                                        \
    using atto##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::atto>;       \
    using femto##name = impl::cnt::                                            \
        container_with_different_prefix<name, lmc::units::prefix::femto>;      \
    using pico##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::pico>;       \
    using nano##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::nano>;       \
    using micro##name = impl::cnt::                                            \
        container_with_different_prefix<name, lmc::units::prefix::micro>;      \
    using milli##name = impl::cnt::                                            \
        container_with_different_prefix<name, lmc::units::prefix::milli>;      \
    using centi##name = impl::cnt::                                            \
        container_with_different_prefix<name, lmc::units::prefix::centi>;      \
    using deci##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::deci>;       \
    using deca##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::deca>;       \
    using hecto##name = impl::cnt::                                            \
        container_with_different_prefix<name, lmc::units::prefix::hecto>;      \
    using kilo##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::kilo>;       \
    using mega##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::mega>;       \
    using giga##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::giga>;       \
    using tera##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::tera>;       \
    using peta##name = impl::cnt::                                             \
        container_with_different_prefix<name, lmc::units::prefix::peta>;       \
    using exa##name = impl::cnt::                                              \
        container_with_different_prefix<name, lmc::units::prefix::exa>;

