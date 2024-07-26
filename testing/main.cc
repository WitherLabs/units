#include <wither/units/length.hh>

#include <iostream>
#include <ostream>

namespace
{

auto
print_megameters(units::mega<units::metres> meters) -> void
{
    std::println(std::cout, "{} megameters", meters.get_measurement());
}

} // namespace

auto
main() -> int
{
    // 10 meters
    units::metres distance { 1000000 };
    print_megameters(distance);

    return 0;
}

