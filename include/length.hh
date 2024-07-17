#pragma once

#include <wither/units/dimension.hh>
#include <wither/units/kind.hh>
#include <wither/units/magnitude.hh>

namespace units
{

using length_dimension = implementation::kind_dimension<
    std::ratio<1>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>>;

struct meters_kind: implementation::kind<length_dimension>
{
    static constexpr double ratio = 1.0;
};

struct feet_kind: implementation::kind<length_dimension>
{
    static constexpr double ratio = 0.3048;
};

using meters = implementation::magnitude<meters_kind>;
using feet   = implementation::magnitude<feet_kind>;

} // namespace units
