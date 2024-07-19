#pragma once

#include <wither/units/angle.hh>

namespace units
{

namespace kind
{

// clang-format off

using steradians = impl::multiply_kinds<radians, radians>;

// clang-format on

} // namespace kind

// clang-format off

using steradians = impl::magnitude<kind::steradians, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

