#include <wither/units/length.hh>

auto
main() -> int
{
    constexpr units::feet   fts { 1 };
    constexpr units::meters mts = fts;
    constexpr double        x   = mts.get_measurement();
    return 0;
}

