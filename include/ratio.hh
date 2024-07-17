#pragma once

#include <type_traits>

#include <ratio>

namespace units::impl
{

struct uratio_tag
{
};

template <typename type> using is_uratio = std::is_base_of<uratio_tag, type>;

template <typename type> constexpr bool is_uratio_v = is_uratio<type>::value;

template <typename type>
concept is_uratio_c = is_uratio_v<type>;

template <typename ratio_t> struct uratio
{
    using ratio = ratio_t;

    template <typename other>
    using convert_to = std::ratio_divide<ratio, typename other::ratio>;
};

} // namespace units::impl
