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

template <util::ratio_cpt ratio_t, typename internal_data_type>
[[nodiscard]]
static constexpr auto
ratio_to_real() -> internal_data_type
{
    return static_cast<internal_data_type>(ratio_t::num)
         / static_cast<internal_data_type>(ratio_t::den);
}

} // namespace util

namespace impl
{
namespace dimension
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
};

template <dimension_cpt dim_a, dimension_cpt dim_b>
static constexpr bool equals
    = std::ratio_equal_v<typename dim_a::length, typename dim_b::length>
   && std::ratio_equal_v<typename dim_a::mass, typename dim_b::mass>
   && std::ratio_equal_v<typename dim_a::time, typename dim_b::time>
   && std::ratio_equal_v<typename dim_a::current, typename dim_b::current>
   && std::ratio_equal_v<
          typename dim_a::temperature,
          typename dim_b::temperature>
   && std::ratio_equal_v<typename dim_a::substance, typename dim_b::substance>
   && std::ratio_equal_v<
          typename dim_a::luminous_intensity,
          typename dim_b::luminous_intensity>;

template <dimension_cpt dim_a, dimension_cpt dim_b>
using add = dimension<
    std::ratio_add<typename dim_a::length, typename dim_b::length>,
    std::ratio_add<typename dim_a::mass, typename dim_b::mass>,
    std::ratio_add<typename dim_a::time, typename dim_b::time>,
    std::ratio_add<typename dim_a::current, typename dim_b::current>,
    std::ratio_add<typename dim_a::temperature, typename dim_b::temperature>,
    std::ratio_add<typename dim_a::substance, typename dim_b::substance>,
    std::ratio_add<
        typename dim_a::luminous_intensity,
        typename dim_b::luminous_intensity>>;

template <dimension_cpt dim_a, dimension_cpt dim_b>
using subtract = dimension<
    std::ratio_subtract<typename dim_a::length, typename dim_b::length>,
    std::ratio_subtract<typename dim_a::mass, typename dim_b::mass>,
    std::ratio_subtract<typename dim_a::time, typename dim_b::time>,
    std::ratio_subtract<typename dim_a::current, typename dim_b::current>,
    std::ratio_subtract<
        typename dim_a::temperature,
        typename dim_b::temperature>,
    std::ratio_subtract<typename dim_a::substance, typename dim_b::substance>,
    std::ratio_subtract<
        typename dim_a::luminous_intensity,
        typename dim_b::luminous_intensity>>;

template <dimension_cpt dim_a, util::ratio_cpt factor>
using times = dimension<
    std::ratio_multiply<typename dim_a::length, factor>,
    std::ratio_multiply<typename dim_a::mass, factor>,
    std::ratio_multiply<typename dim_a::time, factor>,
    std::ratio_multiply<typename dim_a::current, factor>,
    std::ratio_multiply<typename dim_a::temperature, factor>,
    std::ratio_multiply<typename dim_a::substance, factor>,
    std::ratio_multiply<typename dim_a::luminous_intensity, factor>>;

template <dimension_cpt dim, util::ratio_cpt factor>
using divide = dimension<
    std::ratio_divide<typename dim::length, factor>,
    std::ratio_divide<typename dim::mass, factor>,
    std::ratio_divide<typename dim::time, factor>,
    std::ratio_divide<typename dim::current, factor>,
    std::ratio_divide<typename dim::temperature, factor>,
    std::ratio_divide<typename dim::substance, factor>,
    std::ratio_divide<typename dim::luminous_intensity, factor>>;

using none = dimension<
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>,
    std::ratio<0>>;

} // namespace dimension

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

using base = std::ratio<1, 1>;

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

using none = std::ratio<0, 1>;

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
    dimension::dimension_cpt dimension_t,
    util::ratio_cpt          prefix_t,
    util::ratio_cpt          ratio_t,
    util::ratio_cpt          delta_t>
struct kind: kind_tag
{
    using dimension = dimension_t;
    using prefix    = prefix_t;
    using ratio     = ratio_t;
    using delta     = delta_t;
};

template <kind_cpt kind_a, kind_cpt kind_b>
requires dimension::
    equals<typename kind_a::dimension, typename kind_b::dimension>
    struct conversion
{
    using prefix_cvr
        = prefix::convert<typename kind_a::prefix, typename kind_b::prefix>;

    using ratio_cvr
        = ratio::convert<typename kind_a::ratio, typename kind_b::ratio>;

    using delta_cvr
        = delta::convert<typename kind_a::delta, typename kind_b::delta>;

    template <typename internal_data_type>
    [[nodiscard]]
    static constexpr auto
    apply_to(internal_data_type measurement) -> internal_data_type
    {
        constexpr internal_data_type prefix_v
            = util::ratio_to_real<prefix_cvr, internal_data_type>();
        constexpr internal_data_type ratio_v
            = util::ratio_to_real<ratio_cvr, internal_data_type>();
        constexpr internal_data_type delta_v
            = util::ratio_to_real<delta_cvr, internal_data_type>();

        return ratio_v * ((measurement * prefix_v) + delta_v);
    }
};

template <kind_cpt kind_t>
using clone = kind<
    typename kind_t::dimension,
    typename kind_t::prefix_t,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <kind_cpt kind_t, dimension::dimension_cpt dimension_t>
using swap_dimension = kind<
    dimension_t,
    typename kind_t::prefix_t,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <kind_cpt kind_t, util::ratio_cpt prefix_t>
using swap_prefix = kind<
    typename kind_t::dimension,
    prefix_t,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <kind_cpt kind_t, util::ratio_cpt ratio_t>
using swap_ratio = kind<
    typename kind_t::dimension,
    typename kind_t::prefix_t,
    ratio_t,
    typename kind_t::delta>;

template <kind_cpt kind_t, util::ratio_cpt delta_t>
using swap_delta = kind<
    typename kind_t::dimension,
    typename kind_t::prefix_t,
    typename kind_t::ratio,
    delta_t>;

} // namespace kind

namespace magnitude
{

struct magnitude_tag
{
};

template <typename type>
using is_magnitude = std::is_base_of<magnitude_tag, type>;

template <typename type>
constexpr bool is_magnitude_v = is_magnitude<type>::value;

template <typename type>
concept magnitude_cpt = is_magnitude_v<type>;

template <kind::kind_cpt kind_t, typename internal_data_type> struct magnitude
{
public:
    explicit constexpr magnitude(internal_data_type measurement)
    : _measurement { measurement }
    {
    }

    template <kind::kind_cpt new_kind_t>
    [[nodiscard]]
    constexpr auto
    convert_to() -> magnitude<new_kind_t, internal_data_type>
    {
        return magnitude<new_kind_t, internal_data_type> {
            kind::conversion<kind_t, new_kind_t>::apply_to(_measurement)
        };
    }

    [[nodiscard]]
    constexpr auto
    get_measurement() const noexcept -> internal_data_type
    {
        return _measurement;
    }

private:
    internal_data_type _measurement;
};

template <magnitude_cpt magnitude_t, typename internal_data_type>
[[nodiscard]]
constexpr auto
swap_internal_data_type(magnitude_t mag
) noexcept -> magnitude<typename magnitude_t::kind, internal_data_type>
{
    return magnitude<typename magnitude_t::kind, internal_data_type> {
        mag.get_measurement()
    };
}

} // namespace magnitude

} // namespace impl

} // namespace units

