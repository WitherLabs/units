# LibMooncat Units

A generic compile-time-able units meta-library for dimensional analysis

## Purpose
Facilitates operations regarding phyical unit manipulation and dimensional
analysis

## Installation
### Automated
- **UNIX Based**
As `root`: execute the `installer.sh` script in the root directory.
```sh
./install.sh
```

### Manual
- **UNIX Based**
```sh
mkdir -p /usr/include/mooncat/units
mv ./src/*.hh /usr/include/mooncat/units
```

- **Windows**
Pending. We don't have a Windows guy on the team. \
It most likely involves moving the files to your include path under the
`mooncat/units` directory


## Usage
1. Import your desired unit type based on its dimension
2. Use them to represent magnitudes of the specified units
3. Enjoy

Here is an example

```cpp
#include <mooncat/units/length.hh>

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

    // Will automaticlly convert to inchs and feet
    print_meters(distance);
    print_inches(distance);
    print_feet(distance);

    return 0;
}

```

## Creating custom units
Coming Soon. \
It is currently possible to do so, however, there is no friendly api for it.
It is a work in progress.


