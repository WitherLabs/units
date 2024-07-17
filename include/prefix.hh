#pragma once

#include <type_traits>

#include <ratio>

namespace units
{

namespace impl
{
struct prefix_tag
{
};

template <typename type> using is_prefix = std::is_base_of<prefix_tag, type>;

template <typename type> constexpr bool is_prefix_v = is_prefix<type>::value;

template <typename type>
concept is_prefix_c = is_prefix_v<type>;

template <typename ratio_t> struct prefix
{
    using ratio = ratio_t;

    template <typename other>
    using convert_to = std::ratio_divide<ratio, typename other::ratio>;
};
} // namespace impl

namespace prefix
{

#if __INTMAX_WIDTH__ >= 96
#    if __cpp_lib_ratio >= 202306L
#        if __INTMAX_WIDTH__ >= 128
using quecto = impl::prefix<std::quecto>;
#        endif
using ronto = impl::prefix<std::ronto>;
#    endif
using yocto = impl::prefix<std::yocto>;
using zepto = impl::prefix<std::zepto>;
#endif
using atto  = impl::prefix<std::atto>;
using femto = impl::prefix<std::femto>;
using pico  = impl::prefix<std::pico>;
using nano  = impl::prefix<std::nano>;
using micro = impl::prefix<std::micro>;
using milli = impl::prefix<std::milli>;
using centi = impl::prefix<std::centi>;
using deci  = impl::prefix<std::deci>;
using deca  = impl::prefix<std::deca>;
using hecto = impl::prefix<std::hecto>;
using kilo  = impl::prefix<std::kilo>;
using mega  = impl::prefix<std::mega>;
using giga  = impl::prefix<std::giga>;
using tera  = impl::prefix<std::tera>;
using peta  = impl::prefix<std::peta>;
using exa   = impl::prefix<std::exa>;
#if __INTMAX_WIDTH__ >= 96
using zetta = impl::prefix<std::zetta>;
using yotta = impl::prefix<std::yotta>;
#    if __cpp_lib_ratio >= 202306L
using ronna = impl::prefix<std::ronna>;
#        if __INTMAX_WIDTH__ >= 128
using quetta = impl::prefix<std::quetta>;
#        endif
#    endif
#endif

using kibi = impl::prefix<std::ratio<1024>>;
using mebi = impl::prefix<std::ratio<1048576>>;
using gibi = impl::prefix<std::ratio<1073741824>>;
using tebi = impl::prefix<std::ratio<1099511627776>>;
using pebi = impl::prefix<std::ratio<1125899907000000>>;
using exbi = impl::prefix<std::ratio<1152921505000000000>>;

#if __INTMAX_WIDTH__ >= 96
using zebi = impl::prefix<std::ratio<1180591621000000000000>>;
#endif
#if __INTMAX_WIDTH__ >= 128
#    if __cpp_lib_ratio >= 202306L
using yobi = impl::prefix<std::ratio<1208925820000000000000000>>;
#    endif
#endif

} // namespace prefix

} // namespace units
