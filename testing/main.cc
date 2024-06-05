#include "length.hh"
#include "time.hh"
#include "unit_container.hh"
#include "unit_definition.hh"

#include <iostream>
#include <ostream>

constexpr lmc::units::length::kilometers m { 16.5 };
constexpr lmc::units::time::hours        h { 1 };

using kilometer_per_hour = lmc::units::impl::cnt::unit_container<
    lmc::units::impl::def::definition_multiply<
        lmc::units::length::kilometers::definition,
        lmc::units::time::hours::definition>>;

using meter_per_second = lmc::units::impl::cnt::unit_container<
    lmc::units::impl::def::definition_multiply<
        lmc::units::length::meters::definition,
        lmc::units::time::seconds::definition>>;

constexpr kilometer_per_hour kmps = m / h;
constexpr meter_per_second   mps  = kmps;

long double constexpr _m1_        = kmps.get_measurement();
long double constexpr _m2_        = mps.get_measurement();

auto
main() -> int
{
}

