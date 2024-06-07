#include "force.hh"
#include "length.hh"
#include "mass.hh"
#include "time.hh"
#include "unit_container.hh"
#include "velocity.hh"

#include <iostream>
#include <ostream>

lmc::units::force::dynes   p { 10 };
lmc::units::force::newtons n = p;

auto
main() -> int
{
    std::println(
        std::cout,
        "{} dynes= {} newtons",
        p.get_measurement(),
        n.get_measurement()
    );
}

