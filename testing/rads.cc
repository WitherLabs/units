#include <mooncat/units/angle>

#include <cmath>
#include <iostream>
#include <print>

namespace
{

auto
print_sin(lmc::units::angle::radians rads) -> void
{
    println(
        std::cout,
        "sin({} rads) = {}",
        rads.get_measurement(),
        std::sin(rads.get_measurement())
    );
}

auto
print_equivalents(lmc::units::angle::radians rads) -> void
{
    std::println(
        std::cout,
        "{} rads = {} degrees = {} turns",
        rads.get_measurement(),
        lmc::units::angle::degrees { rads }.get_measurement(),
        lmc::units::angle::turns { rads }.get_measurement()
    );
}

auto
do_both(lmc::units::angle::radians rads) -> void
{
    print_equivalents(rads);
    print_sin(rads);
}

} // namespace

auto
main() -> int
{
    do_both(lmc::units::angle::turns { 0 });
    do_both(lmc::units::angle::turns { 0.25 });
    do_both(lmc::units::angle::turns { 0.5 });
    do_both(lmc::units::angle::turns { 0.75 });
    do_both(lmc::units::angle::turns { 1 });
}
