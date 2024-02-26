#pragma once

#ifndef LMC_DEFAULT_INTERNAL_TYPE
#    define LMC_DEFAULT_INTERNAL_TYPE long double
#endif

#define LMC_DEFINE_UNIT_CONVERSION_FACTOR(__name_singular,                     \
                                          __factor_num,                        \
                                          __factor_den)                        \
    namespace conversion {                                                     \
    using __name_singular##_factor =                                           \
        unit_conversion_factor<__factor_num, __factor_den>;                    \
    }

#define LMC_DEFINE_UNIT_CONVERSION_FACTOR_WRT(__name_singular,                 \
                                              __factor_num,                    \
                                              __factor_den,                    \
                                              __name_singular_wrt)             \
    namespace conversion {                                                     \
    using __name_singular##_factor = std::ratio_multiply<                      \
        unit_conversion_factor<__factor_num, __factor_den>,                    \
        __name_singular_wrt##_factor>;                                         \
    }

#define LMC_DEFINE_UNIT_TEMPLATE(__name_singular, __name_plural, __dimension)  \
    template <typename internal_type>                                          \
    using __name_plural##_tt = unit<conversion::__name_singular##_factor,      \
                                    prefix::prefixless,                        \
                                    dimension::__dimension,                    \
                                    internal_type>;                            \
    using __name_plural      = __name_plural##_tt<LMC_DEFAULT_INTERNAL_TYPE>;

#define LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                  \
                                             __name_plural,                    \
                                             __prefix,                         \
                                             __dimension)                      \
    template <typename internal_type>                                          \
    using __prefix##__name_plural##_tt =                                       \
        unit<conversion::__name_singular##_factor,                             \
             prefix::__prefix,                                                 \
             dimension::__dimension,                                           \
             internal_type>;                                                   \
    using __prefix##__name_plural =                                            \
        __prefix##__name_plural##_tt<LMC_DEFAULT_INTERNAL_TYPE>;

#define LMC_DEFINE_UNIT_WITH_ALL_PREFIXES_TEMPLATE(__name_singular,            \
                                                   __name_plural,              \
                                                   __dimension)                \
    LMC_DEFINE_UNIT_TEMPLATE(__name_singular, __name_plural, __dimension)      \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         atto,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         femto,                                \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         pico,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         nano,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         micro,                                \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         milli,                                \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         centi,                                \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         deci,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         deca,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         hecto,                                \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         kilo,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         mega,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         giga,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         tera,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         peta,                                 \
                                         __dimension)                          \
    LMC_DEFINE_UNIT_WITH_PREFIX_TEMPLATE(__name_singular,                      \
                                         __name_plural,                        \
                                         exa,                                  \
                                         __dimension)

#define LMC_DEFINE_UNIT_WHOLE(__name_singular,                                 \
                              __name_plural,                                   \
                              __dimension,                                     \
                              __factor_num,                                    \
                              __factor_den)                                    \
    LMC_DEFINE_UNIT_CONVERSION_FACTOR(__name_singular,                         \
                                      __factor_num,                            \
                                      __factor_den)                            \
    LMC_DEFINE_UNIT_WITH_ALL_PREFIXES_TEMPLATE(__name_singular,                \
                                               __name_plural,                  \
                                               __dimension)

#define LMC_DEFINE_UNIT_WHOLE_WRT(__name_singular,                             \
                                  __name_plural,                               \
                                  __dimension,                                 \
                                  __factor_num,                                \
                                  __factor_den,                                \
                                  __name_singular_wrt)                         \
    LMC_DEFINE_UNIT_CONVERSION_FACTOR_WRT(__name_singular,                     \
                                          __factor_num,                        \
                                          __factor_den,                        \
                                          __name_singular_wrt)                 \
    LMC_DEFINE_UNIT_WITH_ALL_PREFIXES_TEMPLATE(__name_singular,                \
                                               __name_plural,                  \
                                               __dimension)
