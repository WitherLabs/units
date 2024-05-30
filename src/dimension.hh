#pragma once

#include <type_traits>

#include <cstdint>
#include <ratio>

namespace lmc::units::dimensional
{

namespace identification
{

#define DEFINE_DIMENSION_IDENTIFIER(name)                                      \
    struct name##_dimension                                                    \
    {                                                                          \
    };                                                                         \
                                                                               \
    template <typename t>                                                      \
    using is_##name##_dimension = std::is_base_of<name##_dimension, t>;

DEFINE_DIMENSION_IDENTIFIER(length)
DEFINE_DIMENSION_IDENTIFIER(mass)
DEFINE_DIMENSION_IDENTIFIER(time)
DEFINE_DIMENSION_IDENTIFIER(current)
DEFINE_DIMENSION_IDENTIFIER(temperature)
DEFINE_DIMENSION_IDENTIFIER(luminosity)
DEFINE_DIMENSION_IDENTIFIER(substance)

struct dimensional_vector_tag
{
};

template <typename t>
using is_dimensional_vector = std::is_base_of<dimensional_vector_tag, t>;

} // namespace identification

#define DEFINE_BASIC_DIMENSIONAL_RATIO(name)                                   \
    template <std::intmax_t num, std::intmax_t den = 1>                        \
    struct name                                                                \
    : public identification::name##_dimension                                  \
    , public std::ratio<num, den>                                              \
    {                                                                          \
    };

DEFINE_BASIC_DIMENSIONAL_RATIO(length)
DEFINE_BASIC_DIMENSIONAL_RATIO(mass)
DEFINE_BASIC_DIMENSIONAL_RATIO(time)
DEFINE_BASIC_DIMENSIONAL_RATIO(current)
DEFINE_BASIC_DIMENSIONAL_RATIO(temperature)
DEFINE_BASIC_DIMENSIONAL_RATIO(luminosity)
DEFINE_BASIC_DIMENSIONAL_RATIO(substance)

template <
    typename length_dimension,
    typename mass_dimension,
    typename time_dimension,
    typename current_dimension,
    typename temperature_dimension,
    typename luminosity_dimension,
    typename substance_dimension>
requires identification::is_length_dimension<length_dimension>::value
      && identification::is_mass_dimension<mass_dimension>::value
      && identification::is_time_dimension<time_dimension>::value
      && identification::is_current_dimension<current_dimension>::value
      && identification::is_temperature_dimension<temperature_dimension>::value
      && identification::is_luminosity_dimension<luminosity_dimension>::value
      && identification::is_substance_dimension<substance_dimension>::value
struct dimensional_vector: identification::dimensional_vector_tag
{
    using length      = length_dimension;
    using mass        = mass_dimension;
    using time        = time_dimension;
    using current     = current_dimension;
    using temperature = temperature_dimension;
    using luminosity  = luminosity_dimension;
    using substance   = substance_dimension;
};

template <typename vector_a, typename vector_b>
requires identification::is_dimensional_vector<vector_a>::value
      && identification::is_dimensional_vector<vector_b>::value
[[nodiscard]]
constexpr auto
are_dimensional_vectors_equal() -> bool
{
    return std::is_same_v<typename vector_a::length, typename vector_b::length>
        && std::is_same_v<typename vector_a::mass, typename vector_b::mass>
        && std::is_same_v<typename vector_a::time, typename vector_b::time>
        && std::
               is_same_v<typename vector_a::current, typename vector_b::current>
        && std::is_same_v<
               typename vector_a::temperature,
               typename vector_b::temperature>
        && std::is_same_v<
               typename vector_a::luminosity,
               typename vector_b::luminosity>
        && std::is_same_v<
               typename vector_a::substance,
               typename vector_b::substance>;
}

} // namespace lmc::units::dimensional

