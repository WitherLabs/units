#include "dimension.hh"
#include "units.hh"

#include <cstdint>
#include <iostream>
#include <ostream>
#include <ratio>

std::intmax_t constexpr inch_num { 5000 };
std::intmax_t constexpr inch_den { 127 };

using inches_def = lmc::units::unit_definition<
    lmc::units::dimensional::dimensional_vector<
        lmc::units::dimensional::length<1>,
        lmc::units::dimensional::mass<0>,
        lmc::units::dimensional::time<0>,
        lmc::units::dimensional::current<0>,
        lmc::units::dimensional::temperature<0>,
        lmc::units::dimensional::luminosity<0>,
        lmc::units::dimensional::substance<0>>,
    std::ratio<1>,
    std::ratio<inch_num, inch_den>>;

using meters_def = lmc::units::unit_definition<
    lmc::units::dimensional::dimensional_vector<
        lmc::units::dimensional::length<1>,
        lmc::units::dimensional::mass<0>,
        lmc::units::dimensional::time<0>,
        lmc::units::dimensional::current<0>,
        lmc::units::dimensional::temperature<0>,
        lmc::units::dimensional::luminosity<0>,
        lmc::units::dimensional::substance<0>>,
    std::ratio<1>,
    std::ratio<1>>;

using inches = lmc::units::unit_container<inches_def>;
using meters = lmc::units::unit_container<meters_def>;

auto
main() -> int
{
    inches const inch_count { 100 };
    meters const meter_count { inch_count.convert_to<meters>() };

    std::println(
        std::cout,
        "{} inches = {} meters",
        inch_count.get_measurement(),
        meter_count.get_measurement()
    );
}
