#include "capacitance.hh"
#include "catalytic_activity.hh"
#include "charge.hh"
#include "conductance.hh"
#include "current.hh"
#include "dimension.hh"
#include "dose.hh"
#include "energy.hh"
#include "force.hh"
#include "frequency.hh"
#include "inductance.hh"
#include "length.hh"
#include "luminosity.hh"
#include "magnetic_flux.hh"
#include "magnetic_flux_density.hh"
#include "mass.hh"
#include "power.hh"
#include "pressure.hh"
#include "resistance.hh"
#include "substance.hh"
#include "temperature.hh"
#include "time.hh"
#include "voltage.hh"

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<1>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::length::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::mass::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<1>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::time::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<1>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::current::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<1>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::temperature::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<1>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::luminosity::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<0>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<1>>::
                  equals_v<lmc::units::substance::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<-1>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::frequency::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<1>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::force::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<-1>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::pressure::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::energy::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-3>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::power::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<1>,
              lmc::units::impl::dim::current<1>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::charge::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-3>,
              lmc::units::impl::dim::current<-1>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::voltage::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<-2>,
              lmc::units::impl::dim::mass<-1>,
              lmc::units::impl::dim::time<4>,
              lmc::units::impl::dim::current<2>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::capacitance::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-3>,
              lmc::units::impl::dim::current<-2>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::resistance::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<-2>,
              lmc::units::impl::dim::mass<-1>,
              lmc::units::impl::dim::time<3>,
              lmc::units::impl::dim::current<2>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::conductance::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<-1>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::magnetic_flux::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<-1>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::magnetic_flux_density::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<1>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<-2>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::inductance::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<2>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<-2>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<0>>::
                  equals_v<lmc::units::dose::dimension>);

static_assert(lmc::units::impl::dim::dimensional_vector<
              lmc::units::impl::dim::length<0>,
              lmc::units::impl::dim::mass<0>,
              lmc::units::impl::dim::time<-1>,
              lmc::units::impl::dim::current<0>,
              lmc::units::impl::dim::temperature<0>,
              lmc::units::impl::dim::luminosity<0>,
              lmc::units::impl::dim::substance<1>>::
                  equals_v<lmc::units::catalytic_activity::dimension>);

