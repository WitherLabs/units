#pragma once

#include <type_traits>

#include <cstdint>
#include <ratio>

namespace lmc::units::dimensional
{

namespace identification
{

struct length_dimension
{
};

template <typename t>
using is_length_dimension = std ::is_base_of<length_dimension, t>;

struct mass_dimension
{
};

template <typename t>
using is_mass_dimension = std ::is_base_of<mass_dimension, t>;

struct time_dimension
{
};

template <typename t>
using is_time_dimension = std ::is_base_of<time_dimension, t>;

struct current_dimension
{
};

template <typename t>
using is_current_dimension = std ::is_base_of<current_dimension, t>;

struct temperature_dimension
{
};

template <typename t>
using is_temperature_dimension = std ::is_base_of<temperature_dimension, t>;

struct luminosity_dimension
{
};

template <typename t>
using is_luminosity_dimension = std ::is_base_of<luminosity_dimension, t>;

struct substance_dimension
{
};

template <typename t>
using is_substance_dimension = std ::is_base_of<substance_dimension, t>;

struct dimensional_vector_tag
{
};

template <typename t>
using is_dimensional_vector = std::is_base_of<dimensional_vector_tag, t>;

} // namespace identification

template <std ::intmax_t num, std ::intmax_t den = 1>
struct length
: public identification ::length_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct mass
: public identification ::mass_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct time
: public identification ::time_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct current
: public identification ::current_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct temperature
: public identification ::temperature_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct luminosity
: public identification ::luminosity_dimension
, public std ::ratio<num, den>
{
};

template <std ::intmax_t num, std ::intmax_t den = 1>
struct substance
: public identification ::substance_dimension
, public std ::ratio<num, den>
{
};

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
struct are_dimensional_vectors_equal
: std::conditional_t<
      identification::is_dimensional_vector<vector_a>::value
          && identification::is_dimensional_vector<vector_b>::value
          && std::
              is_same_v<typename vector_a::length, typename vector_b::length>
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
              typename vector_b::substance>

      ,
      std::true_type,
      std::false_type>
{
};

} // namespace lmc::units::dimensional

