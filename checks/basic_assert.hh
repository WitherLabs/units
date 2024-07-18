#include <wither/units/current.hh>
#include <wither/units/length.hh>
#include <wither/units/luminous_intensity.hh>
#include <wither/units/mass.hh>
#include <wither/units/substance.hh>
#include <wither/units/temperature.hh>
#include <wither/units/time.hh>
#include <wither/units/units.hh>

static_assert(units::impl::equal_dimensions<
              units::length_dimension,
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
              units::mass_dimension,
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
              units::time_dimension,
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
              units::current_dimension,
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
              units::temperature_dimension,
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
              units::substance_dimension,
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
              units::luminous_intensity_dimension,
              units::impl::dimension<
                  std::ratio<0>, // length
                  std::ratio<0>, // mass
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<1>  // luminous intensity
                  >>);

