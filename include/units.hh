#pragma once

#include <type_traits>

#include <compare>
#include <concepts>
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

template <typename ratio_t>
using ratio_reciprocal = std::conditional_t<
    ratio_t::num == 0,
    std::ratio<0>,
    std::ratio<ratio_t::den, ratio_t::num>>;

template <std::intmax_t iv, ratio_cpt ratio_t>
using mixed_ratio = std::ratio_add<std::ratio<iv>, ratio_t>;

} // namespace util

namespace impl
{

namespace tag
{
struct dimension
{
};

struct kind
{
};

struct magnitude
{
};

} // namespace tag

template <typename type>
using is_dimension = std::is_base_of<tag::dimension, type>;

template <typename type>
constexpr bool is_dimension_v = is_dimension<type>::value;

template <typename type>
concept dimension_cpt = is_dimension_v<type>;

template <
    util::ratio_cpt _mass,
    util::ratio_cpt _length,
    util::ratio_cpt _time,
    util::ratio_cpt _current,
    util::ratio_cpt _temperature,
    util::ratio_cpt _substance,
    util::ratio_cpt _luminous_intensity>
struct dimension: tag::dimension
{
    using mass               = _mass;
    using length             = _length;
    using time               = _time;
    using current            = _current;
    using temperature        = _temperature;
    using substance          = _substance;
    using luminous_intensity = _luminous_intensity;
};

// clang-format off

template <dimension_cpt dim_a, dimension_cpt dim_b>
static constexpr bool equal_dimensions
    =  std::ratio_equal_v<typename dim_a::mass,               typename dim_b::mass>
    && std::ratio_equal_v<typename dim_a::length,             typename dim_b::length>
    && std::ratio_equal_v<typename dim_a::time,               typename dim_b::time>
    && std::ratio_equal_v<typename dim_a::current,            typename dim_b::current>
    && std::ratio_equal_v<typename dim_a::temperature,        typename dim_b::temperature>
    && std::ratio_equal_v<typename dim_a::substance,          typename dim_b::substance>
    && std::ratio_equal_v<typename dim_a::luminous_intensity, typename dim_b::luminous_intensity>; 

template <dimension_cpt dim_a, dimension_cpt dim_b>
using add_dimensions = dimension<
    std::ratio_add<typename dim_a::mass,               typename dim_b::mass>,
    std::ratio_add<typename dim_a::length,             typename dim_b::length>,
    std::ratio_add<typename dim_a::time,               typename dim_b::time>,
    std::ratio_add<typename dim_a::current,            typename dim_b::current>,
    std::ratio_add<typename dim_a::temperature,        typename dim_b::temperature>,
    std::ratio_add<typename dim_a::substance,          typename dim_b::substance>,
    std::ratio_add<typename dim_a::luminous_intensity, typename dim_b::luminous_intensity>
    >;

template <dimension_cpt dim_a, util::ratio_cpt factor>
using multiply_dimension = dimension<
    std::ratio_multiply<typename dim_a::mass,               factor>,
    std::ratio_multiply<typename dim_a::length,             factor>,
    std::ratio_multiply<typename dim_a::time,               factor>,
    std::ratio_multiply<typename dim_a::current,            factor>,
    std::ratio_multiply<typename dim_a::temperature,        factor>,
    std::ratio_multiply<typename dim_a::substance,          factor>,
    std::ratio_multiply<typename dim_a::luminous_intensity, factor>
    >;

template <dimension_cpt dim_a, dimension_cpt dim_b>
using subtract_dimensions = add_dimensions<dim_a, multiply_dimension<dim_b, std::ratio<-1>>>;


template <dimension_cpt dim, util::ratio_cpt factor>
using divide_dimension = multiply_dimension<dim, util::ratio_reciprocal<factor>>;

template <dimension_cpt dim_t>
using reciprocal_dimension = multiply_dimension<dim_t, std::ratio<-1>>;

// clang-format on

using no_dimension = dimension<
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

using none = std::ratio<1>;

} // namespace prefix

namespace ratio
{
template <util::ratio_cpt ratio_a, util::ratio_cpt ratio_b>
using convert = std::ratio_divide<ratio_a, ratio_b>;

template <util::ratio_cpt ratio_a, util::ratio_cpt ratio_b>
using derive = std::ratio_multiply<ratio_a, ratio_b>;

using basic = std::ratio<1, 1>;

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

template <typename type> using is_kind = std::is_base_of<tag::kind, type>;

template <typename type> constexpr bool is_kind_v = is_kind<type>::value;

template <typename type>
concept kind_cpt = is_kind_v<type>;

template <
    dimension_cpt   dimension_t,
    util::ratio_cpt prefix_t,
    util::ratio_cpt ratio_t,
    util::ratio_cpt delta_t>
struct kind: tag::kind
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

        return prefix_v * ratio_v * (measurement + delta_v);
    }
};

template <dimension_cpt dimension_t>
using basic_kind = kind<dimension_t, prefix::none, ratio::basic, delta::none>;

template <kind_cpt kind_t>
using clone_kind = kind<
    typename kind_t::dimension,
    typename kind_t::prefix,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <kind_cpt kind_t, dimension_cpt dimension_t>
using swap_kind_dimension = kind<
    dimension_t,
    typename kind_t::prefix,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <util::ratio_cpt prefix_t, kind_cpt kind_t>
using swap_kind_prefix = kind<
    typename kind_t::dimension,
    prefix_t,
    typename kind_t::ratio,
    typename kind_t::delta>;

template <kind_cpt kind_t, util::ratio_cpt ratio_t>
using swap_kind_ratio = kind<
    typename kind_t::dimension,
    typename kind_t::prefix,
    ratio_t,
    typename kind_t::delta>;

template <kind_cpt kind_t, util::ratio_cpt delta_t>
using swap_kind_delta = kind<
    typename kind_t::dimension,
    typename kind_t::prefix,
    typename kind_t::ratio,
    delta_t>;

template <util::ratio_cpt ratio_t, kind_cpt kind_t>
using derive_kind_prefix = swap_kind_prefix<
    std::ratio_multiply<typename kind_t::prefix, ratio_t>,
    kind_t>;

template <util::ratio_cpt ratio_t, kind_cpt kind_t>
using derive_kind_ratio = kind<
    typename kind_t::dimension,
    typename kind_t::prefix,
    ratio::derive<typename kind_t::ratio, ratio_t>,
    typename kind_t::delta>;

template <util::ratio_cpt delta_t, kind_cpt kind_t>
using derive_kind_delta = kind<
    typename kind_t::dimension,
    typename kind_t::prefix,
    typename kind_t::ratio,
    delta::derive<typename kind_t::ratio, typename kind_t::delta, delta_t>>;

template <kind_cpt kind_t>
using kind_reciprocal = kind<
    reciprocal_dimension<typename kind_t::dimension>,
    util::ratio_reciprocal<typename kind_t::prefix>,
    util::ratio_reciprocal<typename kind_t::ratio>,
    util::ratio_reciprocal<typename kind_t::delta>>;

template <kind_cpt kind_a, kind_cpt kind_b>
using multiply_kinds = kind<
    add_dimensions<typename kind_a::dimension, typename kind_b::dimension>,
    std::ratio_multiply<typename kind_a::prefix, typename kind_b::prefix>,
    std::ratio_multiply<typename kind_a::ratio, typename kind_b::ratio>,
    std::ratio_add<typename kind_a::delta, typename kind_b::delta>>;

template <kind_cpt kind_a, kind_cpt kind_b>
using divide_kinds = multiply_kinds<kind_a, kind_reciprocal<kind_b>>;

template <kind_cpt kind_t> using square_kind = multiply_kinds<kind_t, kind_t>;

template <kind_cpt kind_t>
using cubic_kind = multiply_kinds<square_kind<kind_t>, kind_t>;

template <typename type>
using is_magnitude = std::is_base_of<tag::magnitude, type>;

template <typename type>
constexpr bool is_magnitude_v = is_magnitude<type>::value;

template <typename type>
concept magnitude_cpt = is_magnitude_v<type>;

template <kind_cpt kind_t, typename internal_data_type>
struct magnitude: tag::magnitude
{
public:
    using magkind = kind_t;
    using idt     = internal_data_type;

    explicit constexpr magnitude(internal_data_type measurement)
    : _measurement { measurement }
    {
    }

    template <kind_cpt new_kind_t>
    requires equal_dimensions<
                 typename new_kind_t::dimension,
                 typename magkind::dimension>

    [[nodiscard]]
    constexpr auto
    convert_to() const noexcept -> magnitude<new_kind_t, internal_data_type>
    {
        return magnitude<new_kind_t, internal_data_type> {
            conversion<kind_t, new_kind_t>::apply_to(_measurement)
        };
    }

    [[nodiscard]]
    constexpr auto
    get_measurement() const noexcept -> internal_data_type
    {
        return _measurement;
    }

    template <magnitude_cpt mag_t>
    requires equal_dimensions<
        typename mag_t::magkind::dimension,
        typename magkind::dimension>
    [[nodiscard]]
    constexpr // NOLINTNEXTLINE: No explicit pls
    operator mag_t () const noexcept
    {
        return convert_to<typename mag_t::magkind>();
    }

    [[nodiscard]]
    constexpr auto
    operator+ () const noexcept -> magnitude
    {
        return *this;
    }

    template <magnitude_cpt mag_t>
    requires equal_dimensions<
                 typename mag_t::magkind::dimension,
                 typename magkind::dimension>
    [[nodiscard]]
    constexpr auto
    operator+ (mag_t const mag) const noexcept -> magnitude
    {
        magnitude const converted { mag };
        return magnitude { _measurement + converted._measurement };
    }

    template <magnitude_cpt mag_t>
    requires equal_dimensions<
                 typename mag_t::magkind::dimension,
                 typename magkind::dimension>
    constexpr auto
    operator+= (mag_t const mag) noexcept -> void
    {
        magnitude const converted { mag };
        this->_measurement += converted.get_measurement();
    }

    [[nodiscard]]
    constexpr auto
    operator- () const noexcept -> magnitude
    {
        return magnitude { -_measurement };
    }

    template <magnitude_cpt mag_t>
    requires equal_dimensions<
                 typename mag_t::magkind::dimension,
                 typename magkind::dimension>
    [[nodiscard]]
    constexpr auto
    operator- (mag_t const mag) const noexcept -> magnitude
    {
        magnitude const converted { mag };
        return magnitude { _measurement - converted._measurement };
    }

    template <magnitude_cpt mag_t>
    requires equal_dimensions<
                 typename mag_t::magkind::dimension,
                 typename magkind::dimension>
    constexpr auto
    operator-= (mag_t const mag) noexcept -> void
    {
        magnitude const converted { mag };
        this->_measurement -= converted.get_measurement();
    }

    template <std::floating_point fp>
    [[nodiscard]]
    constexpr auto
    operator* (fp value) -> magnitude
    {
        return magnitude { _measurement * value };
    }

    template <magnitude_cpt mag_t>
    [[nodiscard]]
    constexpr auto
    operator* (mag_t const mag) const noexcept
        -> magnitude<multiply_kinds<magkind, typename mag_t::magkind>, idt>
    {
        using nkind = multiply_kinds<magkind, typename mag_t::magkind>;
        return magnitude<nkind, idt> { get_measurement()
                                       * mag.get_measurement() };
    }

    template <std::floating_point fp>
    [[nodiscard]]
    constexpr auto
    operator/ (fp value) -> magnitude
    {
        return magnitude { _measurement / value };
    }

    template <magnitude_cpt mag_t>
    [[nodiscard]]
    constexpr auto
    operator/ (mag_t const mag) const noexcept
        -> magnitude<divide_kinds<magkind, typename mag_t::magkind>, idt>
    {
        using nkind = divide_kinds<magkind, typename mag_t::magkind>;
        return magnitude<nkind, idt> { get_measurement()
                                       / mag.get_measurement() };
    }

    template <magnitude_cpt mag_t>
    [[nodiscard]]
    constexpr auto
    operator== (mag_t const &mag) const noexcept -> bool
    {
        const decltype(mag_t::idt) omsm
            = mag.template convert_to<magnitude>()._measurement;

        using ntype = std::common_type_t<idt, typename mag_t::idt>;

        return static_cast<ntype>(_measurement) == static_cast<ntype>(omsm);
    }

    template <magnitude_cpt mag_t>
    [[nodiscard]]
    constexpr auto
    operator<=> (mag_t const &mag) const noexcept -> std::conditional_t<
                                                      std::is_integral_v<idt>,
                                                      std::strong_ordering,
                                                      std::partial_ordering>
    {
        using type = std::conditional_t<
            std::is_integral_v<idt>,
            std::strong_ordering,
            std::partial_ordering>;

        const decltype(mag_t::idt) omsm
            = mag.template convert_to<magnitude>()._measurement;

        using ntype = std::common_type_t<idt, typename mag_t::idt>;

        auto const amsm = static_cast<ntype>(_measurement);
        auto const bmsm = static_cast<ntype>(omsm);

        return (amsm == bmsm) ? type::equivalent
             : (amsm > bmsm)  ? type::greater
                              : type::less;
    }

private:
    internal_data_type _measurement;
};

template <std::floating_point fp, magnitude_cpt mag_t>
static constexpr auto
operator* (fp lhs, mag_t rhs) -> mag_t
{
    return rhs * lhs;
}

template <std::floating_point fp, magnitude_cpt mag_t>
static constexpr auto
operator/ (fp lhs, mag_t rhs) -> mag_t
{
    return rhs / lhs;
}

template <typename internal_data_type, magnitude_cpt magnitude_t>
[[nodiscard]]
constexpr auto
swap_internal_data_type(magnitude_t mag
) noexcept -> magnitude<typename magnitude_t::kind, internal_data_type>
{
    return magnitude<typename magnitude_t::kind, internal_data_type> {
        static_cast<internal_data_type>(mag.get_measurement())
    };
}

template <dimension_cpt dimension_t, typename internal_data_type>
using basic = magnitude<basic_kind<dimension_t>, internal_data_type>;

template <magnitude_cpt mag_t>
using clone
    = magnitude<clone_kind<typename mag_t::magkind>, typename mag_t::idt>;

template <magnitude_cpt mag_t, dimension_cpt dimension_t>
using swap_dimension = magnitude<
    swap_kind_dimension<typename mag_t::magkind, dimension_t>,
    typename mag_t::idt>;

template <util::ratio_cpt prefix_t, magnitude_cpt mag_t>
using swap_prefix = magnitude<
    swap_kind_prefix<prefix_t, typename mag_t::magkind>,
    typename mag_t::idt>;

template <magnitude_cpt mag_t, util::ratio_cpt ratio_t>
using swap_ratio = magnitude<
    swap_kind_ratio<typename mag_t::magkind, ratio_t>,
    typename mag_t::idt>;

template <magnitude_cpt mag_t, util::ratio_cpt delta_t>
using swap_delta = magnitude<
    swap_kind_delta<typename mag_t::magkind, delta_t>,
    typename mag_t::idt>;

template <util::ratio_cpt ratio_t, magnitude_cpt mag_t>
using derive_prefix = magnitude<
    derive_kind_prefix<ratio_t, typename mag_t::magkind>,
    typename mag_t::idt>;

template <util::ratio_cpt ratio_t, magnitude_cpt mag_t>
using derive_ratio = magnitude<
    derive_kind_ratio<ratio_t, typename mag_t::magkind>,
    typename mag_t::idt>;

template <util::ratio_cpt ratio_t, magnitude_cpt mag_t>
using derive_delta = magnitude<
    derive_kind_delta<ratio_t, typename mag_t::magkind>,
    typename mag_t::idt>;

template <magnitude_cpt mag_t>
using reciprocal
    = magnitude<kind_reciprocal<typename mag_t::magkind>, typename mag_t::idt>;

template <magnitude_cpt mag_a, magnitude_cpt mag_b>
using multiply = magnitude<
    multiply_kinds<typename mag_a::magkind, typename mag_b::magkind>,
    std::common_type_t<typename mag_a::idt, typename mag_b::idt>>;

template <magnitude_cpt mag_a, magnitude_cpt mag_b>
using divide = multiply<mag_a, reciprocal<mag_b>>;

template <magnitude_cpt mag_a, magnitude_cpt... excess> struct multiply_all_1
{
    using value = mag_a;
};

template <magnitude_cpt mag_a, magnitude_cpt mag_b, magnitude_cpt... excess>
struct multiply_all_2
{
    using value = multiply<mag_a, mag_b>;
};

template <magnitude_cpt... mag_v> struct multiply_all
{
    using value = std::conditional_t<
        sizeof...(mag_v) == 0,
        void,
        std::conditional_t<
            sizeof...(mag_v) == 1,
            typename multiply_all_1<mag_v...>::value,
            std::conditional_t<
                sizeof...(mag_v) == 2,
                typename multiply_all_2<mag_v...>::value,
                multiply_all<mag_v...>>>>;
};

template <magnitude_cpt mag_t> using square = multiply<mag_t, mag_t>;

template <magnitude_cpt mag_t> using cubic = multiply<square<mag_t>, mag_t>;

} // namespace impl

template <impl::magnitude_cpt mag_t>
using atto = impl::swap_prefix<std::atto, mag_t>;
template <impl::magnitude_cpt mag_t>
using femto = impl::swap_prefix<std::femto, mag_t>;
template <impl::magnitude_cpt mag_t>
using pico = impl::swap_prefix<std::pico, mag_t>;
template <impl::magnitude_cpt mag_t>
using nano = impl::swap_prefix<std::nano, mag_t>;
template <impl::magnitude_cpt mag_t>
using micro = impl::swap_prefix<std::micro, mag_t>;
template <impl::magnitude_cpt mag_t>
using milli = impl::swap_prefix<std::milli, mag_t>;
template <impl::magnitude_cpt mag_t>
using centi = impl::swap_prefix<std::centi, mag_t>;
template <impl::magnitude_cpt mag_t>
using deci = impl::swap_prefix<std::deci, mag_t>;
template <impl::magnitude_cpt mag_t>
using deca = impl::swap_prefix<std::deca, mag_t>;
template <impl::magnitude_cpt mag_t>
using hecto = impl::swap_prefix<std::hecto, mag_t>;
template <impl::magnitude_cpt mag_t>
using kilo = impl::swap_prefix<std::kilo, mag_t>;
template <impl::magnitude_cpt mag_t>
using mega = impl::swap_prefix<std::mega, mag_t>;
template <impl::magnitude_cpt mag_t>
using giga = impl::swap_prefix<std::giga, mag_t>;
template <impl::magnitude_cpt mag_t>
using tera = impl::swap_prefix<std::tera, mag_t>;
template <impl::magnitude_cpt mag_t>
using peta = impl::swap_prefix<std::peta, mag_t>;
template <impl::magnitude_cpt mag_t>
using exa = impl::swap_prefix<std::exa, mag_t>;

template <impl::magnitude_cpt mag_t>
using kibi = impl::swap_prefix<std::ratio<1024>, mag_t>;
template <impl::magnitude_cpt mag_t>
using mebi = impl::swap_prefix<std::ratio<1048576>, mag_t>;
template <impl::magnitude_cpt mag_t>
using gibi = impl::swap_prefix<std::ratio<1073741824>, mag_t>;
template <impl::magnitude_cpt mag_t>
using tebi = impl::swap_prefix<std::ratio<1099511627776>, mag_t>;
template <impl::magnitude_cpt mag_t>
using pebi = impl::swap_prefix<std::ratio<1125899907000000>, mag_t>;
template <impl::magnitude_cpt mag_t>
using exbi = impl::swap_prefix<std::ratio<1152921505000000000>, mag_t>;

} // namespace units

