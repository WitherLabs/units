#include "length.hh"

#include <iostream>
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

    return 0;
}

