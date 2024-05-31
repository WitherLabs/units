#include "length.hh"

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

auto
main() -> int
{
    std::println(
        std::cout,
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n"
        "to m = {}\n",
        m0.convert_to<lmc::units::length::meters>().get_measurement(),
        m1.convert_to<lmc::units::length::meters>().get_measurement(),
        m2.convert_to<lmc::units::length::meters>().get_measurement(),
        m3.convert_to<lmc::units::length::meters>().get_measurement(),
        m4.convert_to<lmc::units::length::meters>().get_measurement(),
        m5.convert_to<lmc::units::length::meters>().get_measurement(),
        m6.convert_to<lmc::units::length::meters>().get_measurement(),
        m7.convert_to<lmc::units::length::meters>().get_measurement(),
        m8.convert_to<lmc::units::length::meters>().get_measurement(),
        m9.convert_to<lmc::units::length::meters>().get_measurement(),
        m10.convert_to<lmc::units::length::meters>().get_measurement(),
        m11.convert_to<lmc::units::length::meters>().get_measurement(),
        m12.convert_to<lmc::units::length::meters>().get_measurement(),
        m13.convert_to<lmc::units::length::meters>().get_measurement(),
        m14.convert_to<lmc::units::length::meters>().get_measurement(),
        m15.convert_to<lmc::units::length::meters>().get_measurement()
    );
}
