#include <wither/units/length.hh>

#include <iostream>
#include <ostream>

namespace
{

auto
print_inches(units::inches inches) -> void
{
    std::println(std::cout, "{} inches", inches.get_measurement());
}

auto
print_feet(units::feet feet) -> void
{
    std::println(std::cout, "{} feet", feet.get_measurement());
}

auto
print_meters(units::metres meters) -> void
{
    std::println(std::cout, "{} meters", meters.get_measurement());
}

} // namespace

auto
main() -> int
{
    // 10 meters
    units::metres distance { 10 };

    // Will automatically convert to inches and feet
    print_meters(distance);
    print_inches(distance);
    print_feet(distance);

    return 0;
}

