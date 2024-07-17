#pragma once

#include <wither/units/dimension.hh>

namespace units::implementation
{

template <typename dimension_t> struct kind
{
    using dimension = dimension_t;
};

} // namespace units::implementation

