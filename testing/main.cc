#include "length.hh"
#include "temperature.hh"
#include "unit_container.hh"
#include "unit_definition.hh"

#include <iostream>
#include <ostream>

lmc::units::length::twips constexpr m0 { 1 };
lmc::units::length::thous constexpr m1 { 1 };
lmc::units::length::barleycorns constexpr m2 { 1 };
lmc::units::length::inches constexpr m3 { 1 };
lmc::units::length::hands constexpr m4 { 1 };
lmc::units::length::feet constexpr m5 { 1 };
lmc::units::length::yards constexpr m6 { 1 };
lmc::units::length::chains constexpr m7 { 1 };
lmc::units::length::furlongs constexpr m8 { 1 };
lmc::units::length::miles constexpr m9 { 1 };
lmc::units::length::leagues constexpr m10 { 1 };
lmc::units::length::fathoms constexpr m11 { 1 };
lmc::units::length::cables constexpr m12 { 1 };
lmc::units::length::nautical_miles constexpr m13 { 1 };
lmc::units::length::links constexpr m14 { 1 };
lmc::units::length::rods constexpr m15 { 1 };

lmc::units::temperature::kelvins constexpr k { 0 };
lmc::units::temperature::celsius constexpr d { k };
lmc::units::temperature::kelvins constexpr k2 { d };
lmc::units::temperature::fahrenheit constexpr fd { d };
lmc::units::temperature::fahrenheit constexpr fk { k };

long double constexpr x = d.get_measurement();
long double constexpr y = fd.get_measurement();
long double constexpr z = fk.get_measurement();
long double constexpr w = k2.get_measurement();

auto
main() -> int
{
    std::println(
        std::cout,
        "K = {}, D = {}, F = {}",
        k.get_measurement(),
        d.get_measurement(),
        fk.get_measurement()
    );
}
