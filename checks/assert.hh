// All data sourced from https://metricsystem.net

#include <wither/units/absorbed_dose_rate.hh>
#include <wither/units/acceleration.hh>
#include <wither/units/action.hh>
#include <wither/units/angular_acceleration.hh>
#include <wither/units/angular_momentum.hh>
#include <wither/units/angular_velocity.hh>
#include <wither/units/area.hh>
#include <wither/units/capacitance.hh>
#include <wither/units/catalytic_activity.hh>
#include <wither/units/catalytic_activity_per_unit_volume.hh>
#include <wither/units/charge.hh>
#include <wither/units/concentration.hh>
#include <wither/units/current_density.hh>
#include <wither/units/density.hh>
#include <wither/units/dose.hh>
#include <wither/units/dynamic_viscosity.hh>
#include <wither/units/electric_charge_density.hh>
#include <wither/units/electric_displacement.hh>
#include <wither/units/electric_field_strength.hh>
#include <wither/units/electric_flux_density.hh>
#include <wither/units/electrical_conductance.hh>
#include <wither/units/electrical_resistance.hh>
#include <wither/units/energy.hh>
#include <wither/units/energy_density.hh>
#include <wither/units/entropy.hh>
#include <wither/units/exposure.hh>
#include <wither/units/force.hh>
#include <wither/units/frequency.hh>
#include <wither/units/heat_capacity.hh>
#include <wither/units/heat_flux_density.hh>
#include <wither/units/illuminance.hh>
#include <wither/units/inductance.hh>
#include <wither/units/irradiance.hh>
#include <wither/units/luminance.hh>
#include <wither/units/luminous_efficacy.hh>
#include <wither/units/luminous_energy.hh>
#include <wither/units/luminous_flux.hh>
#include <wither/units/magnetic_field_strength.hh>
#include <wither/units/magnetic_flux_density.hh>
#include <wither/units/molar_energy.hh>
#include <wither/units/molar_entropy.hh>
#include <wither/units/molar_heat_capacity.hh>
#include <wither/units/momentum.hh>
#include <wither/units/permeability.hh>
#include <wither/units/permittivity.hh>
#include <wither/units/plane_angle.hh>
#include <wither/units/power.hh>
#include <wither/units/pressure.hh>
#include <wither/units/radiance.hh>
#include <wither/units/radiant_intensity.hh>
#include <wither/units/radioactivity.hh>
#include <wither/units/solid_angle.hh>
#include <wither/units/specific_energy.hh>
#include <wither/units/specific_entropy.hh>
#include <wither/units/specific_heat_capacity.hh>
#include <wither/units/specific_volume.hh>
#include <wither/units/surface_charge_density.hh>
#include <wither/units/surface_density.hh>
#include <wither/units/surface_tension.hh>
#include <wither/units/thermal_conductivity.hh>
#include <wither/units/torque.hh>
#include <wither/units/velocity.hh>
#include <wither/units/voltage.hh>
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
              units::dimensions::frequency,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::plane_angle,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::solid_angle,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::force,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::pressure,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<-1>, // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::energy,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::power,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::charge,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<1>, // time
                  std::ratio<1>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<0>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::voltage,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-3>, // time
                  std::ratio<-1>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::capacitance,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<-2>, // length
                  std::ratio<4>,  // time
                  std::ratio<2>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electrical_resistance,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-3>, // time
                  std::ratio<-2>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electrical_conductance,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<-2>, // length
                  std::ratio<3>,  // time
                  std::ratio<2>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::magnetic_flux,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<-1>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::magnetic_flux_density,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-2>, // time
                  std::ratio<-1>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::inductance,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<-2>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::luminous_flux,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<0>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<1>  // luminous intensity
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
              units::dimensions::radioactivity,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::dose,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::catalytic_activity,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<1>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::dynamic_viscosity,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<-1>, // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::torque,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::surface_tension,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::action,
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
              units::dimensions::angular_velocity,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::angular_acceleration,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::heat_flux_density,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::irradiance,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::heat_capacity,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::entropy,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::specific_heat_capacity,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::specific_entropy,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::specific_energy,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::thermal_conductivity,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::energy_density,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<-1>, // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electric_field_strength,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-3>, // time
                  std::ratio<-1>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electric_charge_density,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-3>, // length
                  std::ratio<1>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::surface_charge_density,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<1>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electric_flux_density,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<1>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::electric_displacement,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-2>, // length
                  std::ratio<1>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::permittivity,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<-3>, // length
                  std::ratio<4>,  // time
                  std::ratio<2>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::permeability,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<1>,  // length
                  std::ratio<-2>, // time
                  std::ratio<-2>, // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::molar_energy,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<-1>, // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::molar_heat_capacity,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<-1>, // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::molar_entropy,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-2>, // time
                  std::ratio<0>,  // current
                  std::ratio<-1>, // temperature
                  std::ratio<-1>, // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::exposure,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<0>,  // length
                  std::ratio<1>,  // time
                  std::ratio<1>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::absorbed_dose_rate,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::radiant_intensity,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<2>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::radiance,
              units::impl::dimension<
                  std::ratio<1>,  // mass
                  std::ratio<0>,  // length
                  std::ratio<-3>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::catalytic_activity_per_unit_volume,
              units::impl::dimension<
                  std::ratio<0>,  // mass
                  std::ratio<-3>, // length
                  std::ratio<-1>, // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<1>,  // substance
                  std::ratio<0>   // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::luminous_energy,
              units::impl::dimension<
                  std::ratio<0>, // mass
                  std::ratio<0>, // length
                  std::ratio<1>, // time
                  std::ratio<0>, // current
                  std::ratio<0>, // temperature
                  std::ratio<0>, // substance
                  std::ratio<1>  // luminous intensity
                  >>);

static_assert(units::impl::equal_dimensions<
              units::dimensions::luminous_efficacy,
              units::impl::dimension<
                  std::ratio<-1>, // mass
                  std::ratio<-2>, // length
                  std::ratio<3>,  // time
                  std::ratio<0>,  // current
                  std::ratio<0>,  // temperature
                  std::ratio<0>,  // substance
                  std::ratio<1>   // luminous intensity
                  >>);

