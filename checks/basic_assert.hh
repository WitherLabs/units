#include <wither/units/current.hh>
#include <wither/units/length.hh>
#include <wither/units/luminous_intensity.hh>
#include <wither/units/mass.hh>
#include <wither/units/substance.hh>
#include <wither/units/temperature.hh>
#include <wither/units/time.hh>
#include <wither/units/units.hh>

static_assert(units::impl::equal_dimensions<
              units::dim::length,
              units::impl::dimension<
                  std::ratio<1>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::mass,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<1>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::time,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<1>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::current,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<1>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::temperature,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<1>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::substance,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<1>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dim::luminous_intensity,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<1>  // luminous intensity
                  >>);

