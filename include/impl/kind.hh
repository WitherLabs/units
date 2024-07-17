#pragma once

namespace units::implementation
{

class kind
{
public:
    explicit constexpr kind(long double ratio)
    : ratio_to_base_unit { ratio }
    {
    }

    [[nodiscard]]
    constexpr auto
    get_ratio_to_base_unit() const noexcept -> long double
    {
        return ratio_to_base_unit;
    }

private:
    long double ratio_to_base_unit;
};

} // namespace units::implementation

