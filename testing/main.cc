#include "temperature.hh"

#include <iostream>
#include <ostream>

auto
main() -> int
{
    constexpr lmc::units::temperature::kilokelvins k { 1 };
    constexpr lmc::units::temperature::celsius     c { k };
    constexpr lmc::units::temperature::fahrenheit  f { c };

    std::println(
        std::cout,
        "{}Kk = {}c = {}f",
        k.get_measurement(),
        c.get_measurement(),
        f.get_measurement()
    );
}

