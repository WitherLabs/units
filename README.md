# LibMooncat Units

A generic compile-time-able units meta-library for dimensional analysis

## Purpose
Facilitates operations regarding phyical unit manipulation and dimensional
analysis

## Installation
Installation is done through the
[MoonCat Project Manager](https://github.com/MooncatCorps/mooncat-project-manager)
python library

```py
from mooncat.mcpm import actions
actions.install()
```

## Usage
1. Include the header representing your desired unit type
2. Use the units within the `lmc::units::<type>` namespace to represent magnitudes
3. Enjoy

Here is an example

```cpp
#include <mooncat/units/length>

#include <iostream>
#include <ostream>

namespace
{

auto
print_inches(lmc::units::length::inches inches) -> void
{
    std::println(std::cout, "{} inches", inches.get_measurement());
}

auto
print_feet(lmc::units::length::feet feet) -> void
{
    std::println(std::cout, "{} feet", feet.get_measurement());
}

auto
print_meters(lmc::units::length::meters meters) -> void
{
    std::println(std::cout, "{} meters", meters.get_measurement());
}

} // namespace

auto
main() -> int
{
    // 10 meters
    lmc::units::length::meters const distance { 10 };

    // Will automatically convert to inches and feet
    print_meters(distance);
    print_inches(distance);
    print_feet(distance);

    return 0;
}

```

## Creating custom units
Coming Soon. \
It is currently possible to do so, however, there is no friendly api for it.

