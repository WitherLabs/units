// vim: set ft=cpp:

#pragma once

#include <wither/units/units.hh>

namespace units
{
namespace kind
{
using kelvin = impl::kind<
    impl::no_dimension,
    impl::prefix::none,
    impl::ratio::base,
    impl::delta::none>;

using celsius = impl::
    derived_kind<kelvin, impl::ratio::base, std::ratio<27315, 100>>::value;

using fahrenheit
    = impl::derived_kind<celsius, std::ratio<5, 9>, std::ratio<-160, 9>>::value;
} // namespace kind

using kelvin     = impl::magnitude<kind::kelvin, double>;
using celsius    = impl::magnitude<kind::celsius, double>;
using fahrenheit = impl::magnitude<kind::fahrenheit, double>;

} // namespace units

