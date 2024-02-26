#pragma once

#include <concepts>
#include <cstdint>
#include <ratio>
#include <type_traits>

namespace lmc::units {

namespace _im {

struct unit_dimension_inid { };

struct unit_inid { };

template <class>
struct is_ratio : std::false_type { };

template <std::intmax_t num, std::intmax_t denom>
struct is_ratio<std::ratio<num, denom>> : std::true_type { };

template <typename possible_ratio>
constexpr bool is_ratio_v = is_ratio<possible_ratio>::value;

template <class inid>
using is_unit_dimension = std::is_base_of<unit_dimension_inid, inid>;

template <class inid>
constexpr bool is_unit_dimension_v = is_unit_dimension<inid>::value;

template <class inid>
using is_unit = std::is_base_of<unit_inid, inid>;

template <class inid>
constexpr bool is_unit_v = is_unit<inid>::value;

} // namespace _im

template <typename unit_out, typename unit_in>
inline constexpr auto
convert_to(unit_in value) -> unit_out;

template <typename unit_out, typename unit_in>
inline constexpr auto
convert_value(unit_in value) -> typename unit_out::type;

namespace dimension::power {

template <std::intmax_t num, std::intmax_t den>
using length = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using time = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using mass = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using substance = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using luminous = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using temperature = std::ratio<num, den>;

template <std::intmax_t num, std::intmax_t den>
using current = std::ratio<num, den>;

} // namespace dimension::power

template <typename length_dimension      = dimension::power::length<0, 0>,
          typename time_dimension        = dimension::power::time<0, 0>,
          typename mass_dimension        = dimension::power::mass<0, 0>,
          typename substance_dimension   = dimension::power::substance<0, 0>,
          typename luminous_dimension    = dimension::power::luminous<0, 0>,
          typename temperature_dimension = dimension::power::temperature<0, 0>,
          typename current_dimension     = dimension::power::current<0, 0>>
struct unit_dimensions : _im::unit_dimension_inid {
    static_assert(_im::is_ratio<length_dimension>::value);
    static_assert(_im::is_ratio<time_dimension>::value);
    static_assert(_im::is_ratio<mass_dimension>::value);
    static_assert(_im::is_ratio<substance_dimension>::value);
    static_assert(_im::is_ratio<luminous_dimension>::value);
    static_assert(_im::is_ratio<temperature_dimension>::value);
    static_assert(_im::is_ratio<current_dimension>::value);

    using length      = length_dimension;
    using time        = time_dimension;
    using mass        = mass_dimension;
    using substance   = substance_dimension;
    using luminous    = luminous_dimension;
    using temperature = temperature_dimension;
    using current     = current_dimension;
};

template <std::intmax_t numerator = 1, std::intmax_t denominator = 1>
using unit_conversion_factor = std::ratio<numerator, denominator>;

template <std::intmax_t numerator = 1, std::intmax_t denominator = 1>
using unit_prefix = std::ratio<numerator, denominator>;

template <typename conversion_factor_ratio,
          typename prefix_ratio,
          typename dimensions_vector,
          typename internal_type>
class unit : _im::unit_inid {
public:
    static_assert(_im::is_ratio_v<conversion_factor_ratio>);
    static_assert(_im::is_ratio_v<prefix_ratio>);
    static_assert(_im::is_unit_dimension_v<dimensions_vector>);
    static_assert(std::is_floating_point_v<internal_type>);

    using conversion_factor = conversion_factor_ratio;
    using prefix            = prefix_ratio;
    using components        = dimensions_vector;
    using type              = internal_type;

    constexpr unit() = default;

    template <typename ntype,
              typename = std::enable_if_t<std::is_arithmetic_v<ntype>>>
    explicit constexpr unit(ntype const value) noexcept
        : _value(static_cast<internal_type>(value)) { }

    template <typename other_unit,
              typename = std::enable_if_t<_im::is_unit_v<other_unit>>>
    constexpr unit(other_unit const &other) noexcept // NOLINT lmao
        : _value(convert_value<unit>(other)) { }

    template <typename unit_in>
    constexpr auto
    operator= (unit_in unit_to_convert) -> unit & {
        static_assert(_im::is_unit_v<unit_in>);
        this->_value = convert_value<unit, unit_in>(unit_to_convert);
        return *this;
    }

    template <typename unit_in>
    constexpr auto
    operator+ (unit_in unit_to_convert) -> unit {
        static_assert(_im::is_unit_v<unit_in>);
        return unit { _value + unit { unit_to_convert }._value };
    }

    [[nodiscard]] constexpr auto
    value() const -> internal_type {
        return _value;
    }

private:
    internal_type _value;
};

template <typename unit_out, typename unit_in>
inline constexpr auto
convert_value(unit_in value) -> typename unit_out::type {
    static_assert(_im::is_unit_v<unit_out>);
    static_assert(_im::is_unit_v<unit_in>);

    using conversion_factor =
        std::ratio_divide<typename unit_in::conversion_factor,
                          typename unit_out::conversion_factor>;

    using prefix =
        std::ratio_divide<typename unit_in::prefix, typename unit_out::prefix>;

    return typename unit_out::type {
        static_cast<typename unit_out::type>(value.value())
        * (static_cast<typename unit_out::type>(conversion_factor::num)
           / static_cast<typename unit_out::type>(conversion_factor::den))
        * (static_cast<typename unit_out::type>(prefix::num)
           / static_cast<typename unit_out::type>(prefix::den))
    };
};

template <typename unit_out, typename unit_in>
inline constexpr auto
convert_to(unit_in value) -> unit_out {
    static_assert(_im::is_unit_v<unit_out>);
    static_assert(_im::is_unit_v<unit_in>);
    return unit_out { convert_value<unit_out, unit_in>(value) };
};

} // namespace lmc::units
