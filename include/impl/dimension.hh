// vim: set ft=cpp:

#pragma once

namespace units::implementation
{

struct kind_dimension_vector
{
    double length;
    double mass;
    double time;
    double current;
    double temperature;
    double substance;
    double luminous_intensity;
};

class kind_dimension
{
public:
    explicit constexpr kind_dimension(kind_dimension_vector const &vector)
    : dimensions { vector }
    {
    }

    [[nodiscard]]
    constexpr auto
    get_dimensions() const noexcept -> kind_dimension_vector
    {
        return dimensions;
    }

private:
    kind_dimension_vector dimensions;
};

} // namespace units::implementation

