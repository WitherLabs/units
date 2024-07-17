#pragma once

namespace units::implementation
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
        double ratio_cv = kind::ratio / other_kind::ratio;
        return unit<other_kind> { _value * ratio_cv };
    }

    template <typename other_unit>
    [[nodiscard]]
    constexpr
    operator other_unit () const noexcept // NOLINT: No explicit pls
    {
        return convert_to<typename other_unit::kind>();
    }

private:
    double _ratio;
    double _value;
};

} // namespace units::implementation

