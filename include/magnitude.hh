#pragma once

namespace units::implementation
{

template <typename kind_t> class magnitude
{
public:
    using kind = kind_t;

    explicit constexpr magnitude(double value)
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
    convert_to() const noexcept -> magnitude<other_kind>
    {
        double ratio_cv = kind::ratio / other_kind::ratio;
        return magnitude<other_kind> { _value * ratio_cv };
    }

    template <typename other_magnitude>
    [[nodiscard]]
    constexpr
    operator other_magnitude () const noexcept // NOLINT: No explicit pls
    {
        return convert_to<typename other_magnitude::kind>();
    }

private:
    double _value;
};

} // namespace units::implementation

