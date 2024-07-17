#pragma once

#include <ratio>

namespace units::implementation
{

template <
    typename _length,
    typename _mass,
    typename _time,
    typename _current,
    typename _temperature,
    typename _substance,
    typename _luminous_intensity>
struct kind_dimension
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
    using add = kind_dimension<
        std::ratio_add<length, typename other::length>,
        std::ratio_add<mass, typename other::mass>,
        std::ratio_add<time, typename other::time>,
        std::ratio_add<current, typename other::current>,
        std::ratio_add<temperature, typename other::temperature>,
        std::ratio_add<substance, typename other::substance>,
        std::ratio_add<luminous_intensity, typename other::luminous_intensity>>;

    template <typename other>
    using subtract = kind_dimension<
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
    using times = kind_dimension<
        std::ratio_multiply<length, factor>,
        std::ratio_multiply<mass, factor>,
        std::ratio_multiply<time, factor>,
        std::ratio_multiply<current, factor>,
        std::ratio_multiply<temperature, factor>,
        std::ratio_multiply<substance, factor>,
        std::ratio_multiply<luminous_intensity, factor>>;

    template <typename factor>
    using divide = kind_dimension<
        std::ratio_divide<length, factor>,
        std::ratio_divide<mass, factor>,
        std::ratio_divide<time, factor>,
        std::ratio_divide<current, factor>,
        std::ratio_divide<temperature, factor>,
        std::ratio_divide<substance, factor>,
        std::ratio_divide<luminous_intensity, factor>>;
};

} // namespace units::implementation

