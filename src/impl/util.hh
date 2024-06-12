#pragma once

#include <type_traits>

#include <cstdint>
#include <ratio>

namespace lmc::units::impl::util
{

namespace check
{
template <typename> struct is_ratio: std::false_type
{
};

template <std::intmax_t num, std::intmax_t den>
struct is_ratio<std::ratio<num, den>>: std::true_type
{
};

template <typename r> bool constexpr is_ratio_v = is_ratio<r>::value;
} // namespace check

namespace cpt
{
template <typename t>
concept ratio = requires {
    t::num;
    t::den;
} && check::is_ratio_v<t>;

template <typename t>
concept has_internal_ratio = requires {
    typename t::ratio;
    t::value;
} && check::is_ratio_v<typename t::ratio>;
} // namespace cpt

template <cpt::ratio r> using ratio_rec = std::ratio<r::den, r::num>;
template <cpt::ratio r> using ratio_neg = std::ratio<-r::num, r::den>;

template <cpt::ratio r>
constexpr long double ratio_to_real
    = static_cast<long double>(r::num) / static_cast<long double>(r::den);

} // namespace lmc::units::impl::util
