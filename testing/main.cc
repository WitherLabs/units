#include "acceleration.hh"
#include "force.hh"
#include "length.hh"
#include "mass.hh"
#include "time.hh"
#include "unit_container.hh"
#include "velocity.hh"

#include <iostream>
#include <ostream>

constexpr lmc::units::acceleration::meters_per_second_squared g { 9.80665 };
constexpr lmc::units::acceleration::feet_per_second_squared   f { g };

long double constexpr x = f.get_measurement();

auto
main() -> int
{
    std::println(
        std::cout,
        "{}kp = {}N = {}p",
        kp.get_measurement(),
        n.get_measurement(),
        p.get_measurement()
    );
}

