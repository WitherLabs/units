#include "acceleration.hh"

#include <iostream>
#include <ostream>

constexpr lmc::units::acceleration::meters_per_second_squared gravity {
    9.80665L
};
constexpr lmc::units::acceleration::feet_per_second_squared gravity_fts {
    gravity
};

auto
main() -> int
{
    std::println(
        std::cout,
        "g = {}m/s = {}ft/s",
        gravity.get_measurement(),
        gravity_fts.get_measurement()
    );
}

