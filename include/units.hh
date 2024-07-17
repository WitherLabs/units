#pragma once

#include <type_traits>

#include <cstdint>
#include <ratio>

namespace units
{

namespace util
{

template <typename> struct is_ratio: std::false_type
{
};

template <std::intmax_t num, std::intmax_t den>
struct is_ratio<std::ratio<num, den>>: std::true_type
{
};

template <typename r> bool constexpr is_ratio_v = is_ratio<r>::value;

template <typename r>
concept ratio_cpt = is_ratio_v<r>;

template <util::ratio_cpt ratio_t, typename fp>
[[nodiscard]]
static constexpr auto
ratio_to_real() -> fp
{
    return static_cast<fp>(ratio_t::num) / static_cast<fp>(ratio_t::den);
}

} // namespace util

namespace impl
{
struct dimension_tag
{
};

template <typename type>
using is_dimension = std::is_base_of<dimension_tag, type>;

template <typename type>
constexpr bool is_dimension_v = is_dimension<type>::value;

template <typename type>
concept dimension_cpt = is_dimension_v<type>;

template <
    util::ratio_cpt _length,
    util::ratio_cpt _mass,
    util::ratio_cpt _time,
    util::ratio_cpt _current,
    util::ratio_cpt _temperature,
    util::ratio_cpt _substance,
    util::ratio_cpt _luminous_intensity>
struct dimension: dimension_tag
{
    using length             = _length;
    using mass               = _mass;
    using time               = _time;
    using current            = _current;
    using temperature        = _temperature;
    using substance          = _substance;
    using luminous_intensity = _luminous_intensity;

    template <typename other>
    static constexpr bool equals
        = std::ratio_equal_v<length, typename other::length>
       && std::ratio_equal_v<mass, typename other::mass>
       && std::ratio_equal_v<time, typename other::time>
       && std::ratio_equal_v<current, typename other::current>
       && std::ratio_equal_v<temperature, typename other::temperature>
       && std::ratio_equal_v<substance, typename other::substance>
       && std::ratio_equal_v<
              luminous_intensity,
              typename other::luminous_intensity>;

    template <typename other>
    using add = dimension<
        std::ratio_add<length, typename other::length>,
        std::ratio_add<mass, typename other::mass>,
        std::ratio_add<time, typename other::time>,
        std::ratio_add<current, typename other::current>,
        std::ratio_add<temperature, typename other::temperature>,
        std::ratio_add<substance, typename other::substance>,
        std::ratio_add<luminous_intensity, typename other::luminous_intensity>>;

    template <typename other>
    using subtract = dimension<
        std::ratio_subtract<length, typename other::length>,
        std::ratio_subtract<mass, typename other::mass>,
        std::ratio_subtract<time, typename other::time>,
        std::ratio_subtract<current, typename other::current>,
        std::ratio_subtract<temperature, typename other::temperature>,
        std::ratio_subtract<substance, typename other::substance>,
        std::ratio_subtract<
            luminous_intensity,
            typename other::luminous_intensity>>;

    template <typename factor>
    using times = dimension<
        std::ratio_multiply<length, factor>,
        std::ratio_multiply<mass, factor>,
        std::ratio_multiply<time, factor>,
        std::ratio_multiply<current, factor>,
        std::ratio_multiply<temperature, factor>,
        std::ratio_multiply<substance, factor>,
        std::ratio_multiply<luminous_intensity, factor>>;

    template <typename factor>
    using divide = dimension<
        std::ratio_divide<length, factor>,
        std::ratio_divide<mass, factor>,
        std::ratio_divide<time, factor>,
        std::ratio_divide<current, factor>,
        std::ratio_divide<temperature, factor>,
        std::ratio_divide<substance, factor>,
        std::ratio_divide<luminous_intensity, factor>>;
};

using empty_dimension = dimension<
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>>;

namespace prefix
{
template <util::ratio_cpt prefix_a, util::ratio_cpt prefix_b>
using convert = std::ratio_divide<prefix_a, prefix_b>;

#if __INTMAX_WIDTH__ >= 96
#    if __cpp_lib_ratio >= 202306L
#        if __INTMAX_WIDTH__ >= 128
using quecto = std::quecto;
#        endif
using ronto = std::ronto;
#    endif
using yocto = std::yocto;
using zepto = std::zepto;
#endif
using atto  = std::atto;
using femto = std::femto;
using pico  = std::pico;
using nano  = std::nano;
using micro = std::micro;
using milli = std::milli;
using centi = std::centi;
using deci  = std::deci;
using none  = std::ratio<1>;
using deca  = std::deca;
using hecto = std::hecto;
using kilo  = std::kilo;
using mega  = std::mega;
using giga  = std::giga;
using tera  = std::tera;
using peta  = std::peta;
using exa   = std::exa;
#if __INTMAX_WIDTH__ >= 96
using zetta = std::zetta;
using yotta = std::yotta;
#    if __cpp_lib_ratio >= 202306L
using ronna = std::ronna;
#        if __INTMAX_WIDTH__ >= 128
using quetta = std::quetta;
#        endif
#    endif
#endif

using kibi = std::ratio<1024>;
using mebi = std::ratio<1048576>;
using gibi = std::ratio<1073741824>;
using tebi = std::ratio<1099511627776>;
using pebi = std::ratio<1125899907000000>;
using exbi = std::ratio<1152921505000000000>;

#if __INTMAX_WIDTH__ >= 96
using zebi = std::ratio<1180591621000000000000>;
#endif
#if __INTMAX_WIDTH__ >= 128
#    if __cpp_lib_ratio >= 202306L
using yobi = std::ratio<1208925820000000000000000>;
#    endif
#endif

} // namespace prefix

namespace ratio
{
template <util::ratio_cpt ratio_a, util::ratio_cpt ratio_b>
using convert = std::ratio_divide<ratio_a, ratio_b>;

template <util::ratio_cpt ratio_a, util::ratio_cpt ratio_b>
using derive = std::ratio_multiply<ratio_a, ratio_b>;
} // namespace ratio

namespace delta
{
template <util::ratio_cpt delta_a, util::ratio_cpt delta_b>
using convert = std::ratio_subtract<delta_a, typename delta_b::ratio>;

template <
    util::ratio_cpt ratio_a,
    util::ratio_cpt delta_a,
    util::ratio_cpt delta_b>
using derive = std::ratio_add<std::ratio_multiply<ratio_a, delta_a>, delta_b>;
} // namespace delta

namespace kind
{

struct kind_tag
{
};

template <typename type> using is_kind = std::is_base_of<kind_tag, type>;

template <typename type> constexpr bool is_kind_v = is_kind<type>::value;

template <typename type>
concept kind_cpt = is_kind_v<type>;

template <
    dimension_cpt   dimension_t,
    util::ratio_cpt prefix_t,
    util::ratio_cpt ratio_t,
    util::ratio_cpt delta_t>
struct kind: kind_tag
{
    using dimension = dimension_t;
    using prefix    = prefix_t;
    using ratio     = ratio_t;
    using delta     = delta_t;
};

template <kind_cpt kind_a, kind_cpt kind_b> struct conversion
{
    using prefix_cvr
        = prefix::convert<typename kind_a::prefix, typename kind_b::prefix>;

    using ratio_cvr
        = ratio::convert<typename kind_a::ratio, typename kind_b::ratio>;

    using delta_cvr
        = delta::convert<typename kind_a::delta, typename kind_b::delta>;

    template <typename fp>
    [[nodiscard]]
    static constexpr auto
    apply_to(fp measurement) -> fp
    {
        constexpr fp prefix_v = util::ratio_to_real<prefix_cvr, fp>();
        constexpr fp ratio_v  = util::ratio_to_real<ratio_cvr, fp>();
        constexpr fp delta_v  = util::ratio_to_real<delta_cvr, fp>();

        return ratio_v * ((measurement * prefix_v) + delta_v);
    }
};

} // namespace kind

} // namespace impl

} // namespace units

