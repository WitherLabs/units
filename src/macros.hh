#pragma once

#include "unit_container.hh"

template <typename t> struct extract_argument_type;

template <typename t, typename u> struct extract_argument_type<t(u)>
{
    using type = u;
};

#define LMC_UNITS_DEFINE_UNIT_DIMENSION(                                       \
    dimension_name,                                                            \
    length,                                                                    \
    mass,                                                                      \
    time,                                                                      \
    current,                                                                   \
    temperature,                                                               \
    luminosity,                                                                \
    substance                                                                  \
)                                                                              \
    namespace lmc::units::dimension_name                                       \
    {                                                                          \
    using dimension = dimensional::dimensional_vector<                         \
        dimensional::length,                                                   \
        dimensional::mass,                                                     \
        dimensional::time,                                                     \
        dimensional::current,                                                  \
        dimensional::temperature,                                              \
        dimensional::luminosity,                                               \
        dimensional::substance>;                                               \
    } // namespace lmc::units::dimension_name

#define LMC_UNITS_DEFINE_UNIT_TYPE(dimension_name)                             \
    namespace lmc::units::dimension_name                                       \
    {                                                                          \
    struct dimension_name##_unit_tag                                           \
    {                                                                          \
    };                                                                         \
                                                                               \
    template <typename t>                                                      \
    using is_##dimension_name##_unit                                           \
        = std::is_base_of<dimension_name##_unit_tag, t>;                       \
                                                                               \
    template <typename definition>                                             \
    requires lmc::units::dimensional::are_dimensional_vectors_equal<           \
                 typename definition::dimensions,                              \
                 dimension>::value                                             \
              && lmc::units::identification::is_unit_definition<               \
                  definition>::value                                           \
    struct dimension_name##_unit                                               \
    : public lmc::units::unit_container<definition>                            \
    , dimension_name##_unit_tag                                                \
    {                                                                          \
        using container_type = lmc::units::unit_container<definition>;         \
        explicit constexpr dimension_name##_unit(long double measurement)      \
        : container_type { measurement }                                       \
        {                                                                      \
        }                                                                      \
    };                                                                         \
    }

#define LMC_UNITS_DEFINE_UNIT_FRAMEWORK(                                       \
    dimension_name,                                                            \
    length,                                                                    \
    mass,                                                                      \
    time,                                                                      \
    current,                                                                   \
    temperature,                                                               \
    luminosity,                                                                \
    substance                                                                  \
)                                                                              \
    LMC_UNITS_DEFINE_UNIT_DIMENSION(                                           \
        dimension_name,                                                        \
        length,                                                                \
        mass,                                                                  \
        time,                                                                  \
        current,                                                               \
        temperature,                                                           \
        luminosity,                                                            \
        substance                                                              \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_TYPE(dimension_name)

#define LMC_UNITS_DEFINE_UNIT_DEFINITION(                                      \
    dimension_name,                                                            \
    name,                                                                      \
    prefix,                                                                    \
    base_ratio,                                                                \
    delta_ratio                                                                \
)                                                                              \
    namespace lmc::units::dimension_name::definition                           \
    {                                                                          \
    using name = unit_definition<                                              \
        dimension,                                                             \
        extract_argument_type<void(prefix)>::type,                             \
        extract_argument_type<void(base_ratio)>::type,                         \
        extract_argument_type<void(delta_ratio)>::type>;                       \
    }

#define LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, name)                  \
    namespace lmc::units::dimension_name                                       \
    {                                                                          \
    using name = dimension_name##_unit<definition::name>;                      \
    }

#define LMC_UNITS_DEFINE_UNIT_WHOLE(                                           \
    dimension_name,                                                            \
    name,                                                                      \
    prefix,                                                                    \
    base_ratio,                                                                \
    delta_ratio                                                                \
)                                                                              \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        name,                                                                  \
        prefix,                                                                \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, name)

//
// SI PREFIXES
//

#define LMC_UNITS_DEFINE_UNIT_DEFINITION_WITH_SI_PREFIXES(                     \
    dimension_name,                                                            \
    name,                                                                      \
    base_ratio,                                                                \
    delta_ratio                                                                \
)                                                                              \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        exa##name,                                                             \
        std::exa,                                                              \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        peta##name,                                                            \
        std::peta,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        tera##name,                                                            \
        std::tera,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        giga##name,                                                            \
        std::giga,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        mega##name,                                                            \
        std::mega,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        kilo##name,                                                            \
        std::kilo,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        hecto##name,                                                           \
        std::hecto,                                                            \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        deca##name,                                                            \
        std::deca,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        name,                                                                  \
        std::ratio<1>,                                                         \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        deci##name,                                                            \
        std::deci,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        centi##name,                                                           \
        std::centi,                                                            \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        milli##name,                                                           \
        std::milli,                                                            \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        micro##name,                                                           \
        std::micro,                                                            \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        nano##name,                                                            \
        std::nano,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        pico##name,                                                            \
        std::pico,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        femto##name,                                                           \
        std::femto,                                                            \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_DEFINITION(                                          \
        dimension_name,                                                        \
        atto##name,                                                            \
        std::atto,                                                             \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )

#define LMC_UNITS_DEFINE_UNIT_CONTAINER_WITH_SI_PREFIXES(dimension_name, name) \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, exa##name)                 \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, peta##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, tera##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, giga##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, mega##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, kilo##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, hecto##name)               \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, deca##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, name)                      \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, deci##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, centi##name)               \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, milli##name)               \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, micro##name)               \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, nano##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, pico##name)                \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, femto##name)               \
    LMC_UNITS_DEFINE_UNIT_CONTAINER(dimension_name, atto##name)

#define LMC_UNITS_DEFINE_UNIT_WHOLE_WITH_SI_PREFIXES(                          \
    dimension_name,                                                            \
    name,                                                                      \
    base_ratio,                                                                \
    delta_ratio                                                                \
)                                                                              \
    LMC_UNITS_DEFINE_UNIT_DEFINITION_WITH_SI_PREFIXES(                         \
        dimension_name,                                                        \
        name,                                                                  \
        base_ratio,                                                            \
        delta_ratio                                                            \
    )                                                                          \
    LMC_UNITS_DEFINE_UNIT_CONTAINER_WITH_SI_PREFIXES(dimension_name, name)

