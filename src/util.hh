#pragma once

#include <type_traits>

#include <ratio>

namespace lmc::units::util
{
template <typename> struct is_ratio: std::false_type
{
};

template <std::intmax_t num, std::intmax_t den>
struct is_ratio<std::ratio<num, den>>: std::true_type
{
};

template <typename r>
[[nodiscard]]
constexpr auto
convert_ratio_to_real() noexcept -> long double
{
    return static_cast<long double>(r::num) / static_cast<long double>(r::den);
}

} // namespace lmc::units::util
