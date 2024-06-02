#pragma once

#include <type_traits>

#include <cstdint>
#include <ratio>

namespace lmc::units::dimensional
{

namespace identification
{

// Length

struct length_dimension_tag
{
};

template <typename t>
using is_length_dimension = std::is_base_of<length_dimension_tag, t>;

template <typename t>
bool constexpr is_length_dimension_v = is_length_dimension<t>::value;

// Mass

struct mass_dimension_tag
{
};

template <typename t>
using is_mass_dimension = std::is_base_of<mass_dimension_tag, t>;

template <typename t>
bool constexpr is_mass_dimension_v = is_mass_dimension<t>::value;

// Time

struct time_dimension_tag
{
};

template <typename t>
using is_time_dimension_tag = std::is_base_of<time_dimension_tag, t>;

template <typename t>
bool constexpr is_time_dimension_v = is_time_dimension_tag<t>::value;

// Current

struct current_dimension_tag
{
};

template <typename t>
using is_current_dimension = std::is_base_of<current_dimension_tag, t>;

template <typename t>
bool constexpr is_current_dimension_v = is_current_dimension<t>::value;

// Temperature

struct temperature_dimension_tag
{
};

template <typename t>
using is_temperature_dimension = std::is_base_of<temperature_dimension_tag, t>;

template <typename t>
bool constexpr is_temperature_dimension_v = is_temperature_dimension<t>::value;

// Luminosity

struct luminosity_dimension_tag
{
};

template <typename t>
using is_luminosity_dimension = std::is_base_of<luminosity_dimension_tag, t>;

template <typename t>
bool constexpr is_luminosity_dimension_v = is_luminosity_dimension<t>::value;

// Substance

struct substance_dimension_tag
{
};

template <typename t>
using is_substance_dimension = std::is_base_of<substance_dimension_tag, t>;

template <typename t>
bool constexpr is_substance_dimension_v = is_substance_dimension<t>::value;

// Dimensional Vector

struct dimensional_vector_tag
{
};

template <typename t>
using is_dimensional_vector = std::is_base_of<dimensional_vector_tag, t>;

template <typename t>
bool constexpr is_dimensional_vector_v = is_dimensional_vector<t>::value;

} // namespace identification

template <std::intmax_t num, std::intmax_t den = 1>
struct length
: identification::length_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct mass
: identification::mass_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct time
: identification::time_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct current
: identification::current_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct temperature
: identification::temperature_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct luminosity
: identification::luminosity_dimension_tag
, public std::ratio<num, den>
{
};

template <std::intmax_t num, std::intmax_t den = 1>
struct substance
: identification::substance_dimension_tag
, public std::ratio<num, den>
{
};

template <
    typename length_t,
    typename mass_t,
    typename time_t,
    typename current_t,
    typename temperature_t,
    typename luminosity_t,
    typename substance_t>
requires identification::is_length_dimension_v<length_t>
      && identification::is_mass_dimension_v<mass_t>
      && identification::is_time_dimension_v<time_t>
      && identification::is_current_dimension_v<current_t>
      && identification::is_temperature_dimension_v<temperature_t>
      && identification::is_luminosity_dimension_v<luminosity_t>
      && identification::is_substance_dimension_v<substance_t>
struct dimensional_vector: identification::dimensional_vector_tag
{
    using length      = length_t;
    using mass        = mass_t;
    using time        = time_t;
    using current     = current_t;
    using temperature = temperature_t;
    using luminosity  = luminosity_t;
    using substance   = substance_t;
};

template <typename vector_a_t, typename vector_b_t>
struct dimensional_vectors_are_equal
: std::conditional_t<
      identification::is_dimensional_vector_v<vector_a_t>
          && identification::is_dimensional_vector_v<vector_b_t>
          && std::is_same_v<
              typename vector_a_t::length,
              typename vector_b_t::length>
          && std::
              is_same_v<typename vector_a_t::mass, typename vector_b_t::mass>
          && std::
              is_same_v<typename vector_a_t::time, typename vector_b_t::time>
          && std::is_same_v<
              typename vector_a_t::current,
              typename vector_b_t::current>
          && std::is_same_v<
              typename vector_a_t::temperature,
              typename vector_b_t::temperature>
          && std::is_same_v<
              typename vector_a_t::luminosity,
              typename vector_b_t::luminosity>
          && std::is_same_v<
              typename vector_a_t::substance,
              typename vector_b_t::substance>

      ,
      std::true_type,
      std::false_type>
{
};

template <typename vector_a_t, typename vector_b_t>
bool constexpr dimensional_vectors_are_equal_v
    = dimensional_vectors_are_equal<vector_a_t, vector_b_t>::value;

} // namespace lmc::units::dimensional

