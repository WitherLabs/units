#include <mooncat/units/angle>
#include <mooncat/units/length>

#include <iostream>
#include <numbers>
#include <ostream>

namespace
{

auto
print_inches(lmc::units::length::inches inches) -> void
{
    std::println(std::cout, "{} inches", inches.get_measurement());
}

auto
print_feet(lmc::units::length::feet feet) -> void
{
    std::println(std::cout, "{} feet", feet.get_measurement());
}

auto
print_meters(lmc::units::length::meters meters) -> void
{
    std::println(std::cout, "{} meters", meters.get_measurement());
}

} // namespace

auto
main() -> int
{
    // 10 meters
    lmc::units::length::meters const distance { 10 };

    // Will automaticlly convert to inchs and feet
    print_meters(distance);
    print_inches(distance);
    print_feet(distance);

    std::println(std::cout, "{}", 2.0L * std::numbers::pi_v<long double>);

    return 0;
}

