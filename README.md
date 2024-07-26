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
#include <wither/units/acceleration.hh>

#include <iostream>
#include <ostream>

// Uniform acceleration of 18.5 m/s to 46.1m/s over a span of 2.47s

auto
main() -> int
{
    constexpr units::metres_per_second v_i { 18.5L };
    constexpr units::metres_per_second v_f { 46.1L };
    constexpr units::seconds           time { 2.47L };

    constexpr units::metres_per_second_squared acceleration
        = (v_f - v_i) / time;

    constexpr units::metres distance
        = v_i * time + (0.5 * acceleration * time * time);

    std::println(
        std::cout,
        "acceleration = {}ms^2\ndistance = {}m",
        acceleration.get_measurement(),
        distance.get_measurement()
    );

    return 0;
}
```

## Requirements: Adding Units to The Library
1. Must be a well-known unit
2. Must not have multiple definitions throughout history (under the same name)
 **OR** Must be standardized under some historical agreement still up-to-date
3. Must not be outdated

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

