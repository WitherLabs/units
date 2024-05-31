#include "length.hh"

#include <iostream>
#include <ostream>

auto
main() -> int
{
    lmc::units::length::feet const   feet_count { 1 };
    lmc::units::length::meters const meter_count = feet_count;

    std::println(
        std::cout,
        "{} foot/feet = {:10f} meter(s); cv = {}",
        feet_count.get_measurement(),
        meter_count.get_measurement(),
        feet_count.get_conversion_factor_to<lmc::units::length::meters>()
    );
}
