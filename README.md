# LibMooncat Units

A generic compile-time-able units meta-library for dimensional analysis

## Purpose
Facilitates operations regarding phyical unit manipulation and dimensional
analysis

## Installation
### Automated
- **UNIX Based** \
As `root`: execute the `installer.sh` script in the root directory.
```sh
./install.sh
```
This will copy the project's headers over to `/usr/include/mooncat/units`

- **Windows** \
As an administrator: execute the `installer.ps1` script in the root directory
```ps1
& .\installer.ps1
```
This will copy the project's headers over to
`C:\Program Files\Mooncat\include\mooncat\units`in order to facilitate
inclusion in MS projects

### Manual
- **UNIX Based**
```sh
mkdir -p /usr/include/mooncat/units
mv ./include/* /usr/include/mooncat/units
```

- **Windows** \
Copy the contents of the `include` directory over to
`C:\Program Files\Mooncat\include\mooncat\units`

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

