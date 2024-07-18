# Units

A generic compile-time-able units meta-library for dimensional analysis

## Purpose
Facilitates operations regarding phyical unit manipulation and dimensional
analysis

## Installation
Sorry, postponed!

## Usage
1. Include the header representing your desired unit type
2. Use the units within the `units` namespace to represent magnitudes

Here is an example

```cpp
#include <wither/units/length.hh>

#include <iostream>
#include <ostream>

namespace
{

auto
print_inches(units::inches inches) -> void
{
    std::println(std::cout, "{} inches", inches.get_measurement());
}

auto
print_feet(units::feet feet) -> void
{
    std::println(std::cout, "{} feet", feet.get_measurement());
}

auto
print_meters(units::meters meters) -> void
{
    std::println(std::cout, "{} meters", meters.get_measurement());
}

} // namespace

auto
main() -> int
{
    // 10 meters
    units::meters const distance { 10 };

    // Will automatically convert to inches and feet
    print_meters(distance);
    print_inches(distance);
    print_feet(distance);

    return 0;
}

```

## Creating custom units
Coming Soon. \
It is currently possible to do so, however, there is no explicit api for it.

## How does it work?
A more in-depth explanation will be provided soon. Expect a wiki.

For now, any unit you see has the following internal structure:
Here, we use degrees fahrenheit as an example

```
┌ units::fahrenheit temp{144.6};
│
├ Magnitude: 144.6
└ Kind: Fahrenheit
  ├ Dimension : Temperature
  ├ Prefix    : None    : 1
  ├ Ratio     : Derived : 5 / 9
  ├ Delta     : Derived : 45967 / 180
  └ Derived from: Celsius [+5463, 20]
    ├ Dimension : Temperature
    ├ Prefix    : None    : 1
    ├ Ratio     : Basic   : 1
    ├ Delta     : Derived : 5463 / 20
    └ Derived from: Kelvins
      ├ Dimension : Temperature
      ├ Prefix    : None  : 1
      ├ Ratio     : Basic : 1
      ├ Delta     : None  : 0
      └ Kelvins are a base unit
```

These are not really nested; they are merely derived. Each entity bases off
of another. After conversion ratios have been fully determined, the unit
operates independently.

