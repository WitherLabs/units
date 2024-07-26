#include <wither/units/acceleration.hh>
#include <wither/units/angular_momentum.hh>
#include <wither/units/area.hh>
#include <wither/units/concentration.hh>
#include <wither/units/current_density.hh>
#include <wither/units/density.hh>
#include <wither/units/luminance.hh>
#include <wither/units/magnetic_field_strength.hh>
#include <wither/units/momentum.hh>
#include <wither/units/specific_volume.hh>
#include <wither/units/surface_density.hh>
#include <wither/units/velocity.hh>
#include <wither/units/volume.hh>
#include <wither/units/volumetric_flow_rate.hh>
#include <wither/units/wavenumber.hh>

static_assert(units::impl::equal_dimensions<
              units::dimensions::area,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<2>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::volume,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<3>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::velocity,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::acceleration,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::volumetric_flow_rate,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<3>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::wavenumber,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-1>, // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::density,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<-3>, // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::surface_density,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::specific_volume,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<3>,  // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::momentum,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::angular_momentum,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::current_density,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<0>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::magnetic_field_strength,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-1>, // length
                  std::ratio<0>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::concentration,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-3>, // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<1>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::illuminance,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<0>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<1>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::impl::no_dimension,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

