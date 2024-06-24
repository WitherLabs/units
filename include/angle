// vim: set ft=cpp:

#pragma once

#include <mooncat/units/length>

namespace lmc::units::angle
{

constexpr std::intmax_t pi_num = 353981633974483;
constexpr std::intmax_t pi_den = 2500000000000000;

using pi_ratio = std::ratio_add<std::ratio<3>, std::ratio<pi_num, pi_den>>;

using radians = impl::cnt::unit_container<impl::def::definition_divide<
    length::meters::definition,
    length::meters::definition>>;

using dimension = radians::definition::dimension;

using turns
    = impl::abbr::derive<std::ratio_multiply<std::ratio<2>, pi_ratio>, radians>;

using degrees = impl::abbr::derive<std::ratio<1, 360>, turns>;

} // namespace lmc::units::angle

inline namespace ilmc
{
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(angle, radians)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(angle, turns)
LMC_UNITS_CREATE_UNIT_LITERAL_OPERATOR(angle, degrees)
} // namespace ilmc
