#pragma once

#include <wither/units/length.hh>

namespace units
{

namespace kind
{

// clang-format off

using radians = impl::divide_kinds<metres, metres>;

// clang-format on

} // namespace kind

// clang-format off

using radians = impl::magnitude<kind::radians, double>;

// clang-format on

namespace dim
{

} // namespace dim

} // namespace units

