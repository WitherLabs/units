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

        return ratio_v * ((measurement * prefix_v) + delta_v);
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
    typename kind_t::ratio_t,
    delta::derive<typename kind_t::ratio, typename kind_t::delta, delta_t>>;

template <kind_cpt kind_t>
using kind_reciprocal = kind<
    reciprocal_dimension<typename kind_t::dimension>,
    typename kind_t::prefix,
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
using cube_kind = multiply_kinds<square_kind<kind_t>, kind_t>;

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

    template <magnitude_cpt magnitude_t>
    [[nodiscard]]
    constexpr // NOLINTNEXTLINE: No explicit pls
    operator magnitude_t () const noexcept
    {
        return convert_to<typename magnitude_t::magkind>();
    }

    [[nodiscard]]
    constexpr auto
    operator+ () const noexcept -> magnitude
    {
        return magnitude { _measurement };
    }

    [[nodiscard]]
    constexpr auto
    operator- () const noexcept -> magnitude
    {
        return magnitude { -_measurement };
    }

    template <magnitude_cpt magnitude_t>
    requires equal_dimensions<
                 typename magkind::dimension,
                 typename magnitude_t::magkind::dimension>
    [[nodiscard]]
    constexpr auto
    operator+ (magnitude_t const mag) const noexcept -> magnitude
    {
        magnitude const converted { mag };
        return magnitude { _measurement + converted._measurement };
    }

    template <magnitude_cpt magnitude_t>
    requires equal_dimensions<
                 typename magkind::dimension,
                 typename magnitude_t::magkind::dimension>
    [[nodiscard]]
    constexpr auto
    operator- (magnitude_t const mag) const noexcept -> magnitude
    {
        magnitude const converted { mag };
        return magnitude { _measurement - converted._measurement };
    }

    [[nodiscard]]
    constexpr auto
    operator* (internal_data_type value) -> magnitude
    {
        return magnitude { _measurement * value };
    }

    template <magnitude_cpt magnitude_t>
    [[nodiscard]]
    constexpr auto
    operator* (magnitude_t const mag) const noexcept
        -> magnitude<
            multiply_kinds<magkind, typename magnitude_t::magkind>,
            internal_data_type>
    {
        using nkind = multiply_kinds<magkind, typename magnitude_t::magkind>;

        using bk1 = basic_kind<typename magkind::dimension>;
        using bk2 = basic_kind<typename magnitude_t::magkind::dimension>;
        using bkp = multiply_kinds<bk1, bk2>;

        auto const mag1 = convert_to<bk1>();
        auto const mag2 = mag.template convert_to<bk2>();

        auto const magp
            = magnitude<bkp, internal_data_type> { mag1.get_measurement()
                                                   * mag2.get_measurement() };
        return magp.template convert_to<nkind>();
    }

    [[nodiscard]]
    constexpr auto
    operator/ (internal_data_type value) -> magnitude
    {
        return magnitude { _measurement / value };
    }

    template <magnitude_cpt magnitude_t>
    [[nodiscard]]
    constexpr auto
    operator/ (magnitude_t const mag) const noexcept
        -> magnitude<
            divide_kinds<magkind, typename magnitude_t::magkind>,
            internal_data_type>
    {
        using nkind = divide_kinds<magkind, typename magnitude_t::magkind>;

        using bk1 = basic_kind<typename magkind::dimension>;
        using bk2 = basic_kind<typename magnitude_t::magkind::dimension>;
        using bkp = divide_kinds<bk1, bk2>;

        auto const mag1 = convert_to<bk1>();
        auto const mag2 = mag.template convert_to<bk2>();

        auto const magp
            = magnitude<bkp, internal_data_type> { mag1.get_measurement()
                                                   / mag2.get_measurement() };
        return magp.template convert_to<nkind>();
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

} // namespace impl

} // namespace units

