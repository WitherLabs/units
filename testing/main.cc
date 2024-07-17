#include <wither/units/kind.hh>

auto
main() -> int
{
    constexpr double mts = 1;
    using meters         = units::impl::kind<
                units::impl::empty_dimension,
                units::prefixes::none,
                units::impl::ratio<std::ratio<1, 1>>,
                units::impl::delta<std::ratio<0>>>;
    using feet = units::impl::kind<
        units::impl::empty_dimension,
        units::prefixes::none,
        units::impl::ratio<std::ratio<381, 1250>>,
        units::impl::delta<std::ratio<0>>>;

    using ftm            = units::impl::conversion_factor_between<meters, feet>;
    constexpr double fts = ftm::apply_to_measurement(mts);

    return 0;
}

