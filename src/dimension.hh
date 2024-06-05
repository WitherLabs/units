#pragma once

#include "util.hh"

namespace lmc::units::impl::dim
{

namespace check
{

namespace tag
{
struct length_dimension
{
};

struct mass_dimension
{
};

struct time_dimension
{
};

struct current_dimension
{
};

struct temperature_dimension
{
};

struct luminosity_dimension
{
};

struct substance_dimension
{
};

struct dimensional_vector
{
};
} // namespace tag

// Length

template <typename t>
using is_length_dimension = std::is_base_of<tag::length_dimension, t>;

template <typename t>
bool constexpr is_length_dimension_v = is_length_dimension<t>::value;

// Mass

template <typename t>
using is_mass_dimension = std::is_base_of<tag::mass_dimension, t>;

template <typename t>
bool constexpr is_mass_dimension_v = is_mass_dimension<t>::value;

// Time

template <typename t>
using is_time_dimension = std::is_base_of<tag::time_dimension, t>;

template <typename t>
bool constexpr is_time_dimension_v = is_time_dimension<t>::value;

// Current

template <typename t>
using is_current_dimension = std::is_base_of<tag::current_dimension, t>;

template <typename t>
bool constexpr is_current_dimension_v = is_current_dimension<t>::value;

// Temperature

template <typename t>
using is_temperature_dimension = std::is_base_of<tag::temperature_dimension, t>;

template <typename t>
bool constexpr is_temperature_dimension_v = is_temperature_dimension<t>::value;

// Luminosity

template <typename t>
using is_luminosity_dimension = std::is_base_of<tag::luminosity_dimension, t>;

template <typename t>
bool constexpr is_luminosity_dimension_v = is_luminosity_dimension<t>::value;

// Substance

template <typename t>
using is_substance_dimension = std::is_base_of<tag::substance_dimension, t>;

template <typename t>
bool constexpr is_substance_dimension_v = is_substance_dimension<t>::value;

// Dimensional Vector

template <typename t>
using is_dimensional_vector = std::is_base_of<tag::dimensional_vector, t>;

template <typename t>
bool constexpr is_dimensional_vector_v = is_dimensional_vector<t>::value;

} // namespace check

namespace cpt
{

template <typename t>
concept length
    = check::is_length_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept mass
    = check::is_mass_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept time
    = check::is_time_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept current
    = check::is_current_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept temperature
    = check::is_temperature_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept luminosity
    = check::is_luminosity_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept substance
    = check::is_substance_dimension_v<t> && util::cpt::has_internal_ratio<t>;

template <typename t>
concept dimensional_vector = check::is_dimensional_vector_v<t>;

} // namespace cpt

template <std::intmax_t num, std::intmax_t den = 1>
struct length: check::tag::length_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r> using length_from_ratio = length<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct mass: check::tag::mass_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r> using mass_from_ratio = mass<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct time: check::tag::time_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r> using time_from_ratio = time<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct current: check::tag::current_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r>
using current_from_ratio = current<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct temperature: check::tag::temperature_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r>
using temperature_from_ratio = temperature<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct luminosity: check::tag::luminosity_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r>
using luminosity_from_ratio = luminosity<r::num, r::den>;

template <std::intmax_t num, std::intmax_t den = 1>
struct substance: check::tag::substance_dimension
{
    using ratio                        = std::ratio<num, den>;
    static constexpr long double value = util::ratio_to_real<ratio>;
};

template <util::cpt::ratio r>
using substance_from_ratio = substance<r::num, r::den>;

template <
    cpt::length      length_t,
    cpt::mass        mass_t,
    cpt::time        time_t,
    cpt::current     current_t,
    cpt::temperature temperature_t,
    cpt::luminosity  luminosity_t,
    cpt::substance   substance_t>
struct dimensional_vector: check::tag::dimensional_vector
{
    using length      = length_t;
    using mass        = mass_t;
    using time        = time_t;
    using current     = current_t;
    using temperature = temperature_t;
    using luminosity  = luminosity_t;
    using substance   = substance_t;

    template <cpt::dimensional_vector t>
    using equals = typename std::conditional_t<
        check::is_dimensional_vector_v<t>
            && std::is_same_v<length, typename t::length>
            && std::is_same_v<mass, typename t::mass>
            && std::is_same_v<time, typename t::time>
            && std::is_same_v<current, typename t::current>
            && std::is_same_v<temperature, typename t::temperature>
            && std::is_same_v<luminosity, typename t::luminosity>
            && std::is_same_v<substance, typename t::substance>,
        std::true_type,
        std::false_type>;

    template <cpt::dimensional_vector t>
    static constexpr bool equals_v = equals<t>::value;

    template <cpt::dimensional_vector t>
    using add = dimensional_vector<
        length_from_ratio<
            std::ratio_add<typename length::ratio, typename t::length::ratio>>,
        mass_from_ratio<
            std::ratio_add<typename mass::ratio, typename t::mass::ratio>>,
        time_from_ratio<
            std::ratio_add<typename time::ratio, typename t::time::ratio>>,
        current_from_ratio<std::ratio_add<
            typename current::ratio,
            typename t::current::ratio>>,
        temperature_from_ratio<std::ratio_add<
            typename temperature::ratio,
            typename t::temperature::ratio>>,
        luminosity_from_ratio<std::ratio_add<
            typename luminosity::ratio,
            typename t::luminosity::ratio>>,
        substance_from_ratio<std::ratio_add<
            typename substance::ratio,
            typename t::substance::ratio>>>;

    template <cpt::dimensional_vector t>
    using subtract = dimensional_vector<
        length_from_ratio<std::ratio_subtract<
            typename length::ratio,
            typename t::length::ratio>>,
        mass_from_ratio<
            std::ratio_subtract<typename mass::ratio, typename t::mass::ratio>>,
        time_from_ratio<
            std::ratio_subtract<typename time::ratio, typename t::time::ratio>>,
        current_from_ratio<std::ratio_subtract<
            typename current::ratio,
            typename t::current::ratio>>,
        temperature_from_ratio<std::ratio_subtract<
            typename temperature::ratio,
            typename t::temperature::ratio>>,
        luminosity_from_ratio<std::ratio_subtract<
            typename luminosity::ratio,
            typename t::luminosity::ratio>>,
        substance_from_ratio<std::ratio_subtract<
            typename substance::ratio,
            typename t::substance::ratio>>>;

    template <util::cpt::ratio r>
    using multiply = dimensional_vector<
        length_from_ratio<std::ratio_multiply<typename length::ratio, r>>,
        mass_from_ratio<std::ratio_multiply<typename mass::ratio, r>>,
        time_from_ratio<std::ratio_multiply<typename time::ratio, r>>,
        current_from_ratio<std::ratio_multiply<typename current::ratio, r>>,
        temperature_from_ratio<
            std::ratio_multiply<typename temperature::ratio, r>>,
        luminosity_from_ratio<
            std::ratio_multiply<typename luminosity::ratio, r>>,
        substance_from_ratio<
            std::ratio_multiply<typename substance::ratio, r>>>;
};

} // namespace lmc::units::impl::dim

