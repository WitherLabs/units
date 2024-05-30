#pragma once

#include "util.hh"

namespace lmc::units::prefixes
{

template <typename ratio_from, typename ratio_to>
requires util::is_ratio<ratio_from>::value && util::is_ratio<ratio_to>::value
[[nodiscard]]
constexpr auto
get_ratio_conversion_factor() -> long double
{
    return util::convert_ratio_to_real<ratio_from>()
         / util::convert_ratio_to_real<ratio_to>();
}

} // namespace lmc::units::prefixes

