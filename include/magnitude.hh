#pragma once

namespace units::impl
{

template <typename kind_t> class unit
{
public:
    using kind = kind_t;

    explicit constexpr unit(double value)
    : _value { value }
    {
    }

    [[nodiscard]]
    constexpr auto
    get_measurement() const noexcept -> double
    {
        return _value;
    }

    template <typename other_kind>
    [[nodiscard]]
    constexpr auto
    convert_to() const noexcept -> unit<other_kind>
    {
        using prefix_ratio =
            typename kind::prefix::template convert_to<other_kind>;
        using uratio_ratio =
            typename kind::uratio::template convert_to<other_kind>;
        using udelta_ratio = typename kind::udelta::
            template convert_to<uratio_ratio, other_kind>;

        constexpr double factor =
    }

    template <typename other_unit>
    [[nodiscard]]
    constexpr
    operator other_unit () const noexcept // NOLINT: No explicit pls
    {
        return convert_to<typename other_unit::kind>();
    }

private:
    double _value;
};

} // namespace units::impl

