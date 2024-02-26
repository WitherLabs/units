#pragma once

#include <mooncat/units/meta.hh>

namespace lmc::units::prefix {

using atto       = std::atto;
using femto      = std::femto;
using pico       = std::pico;
using nano       = std::nano;
using micro      = std::micro;
using milli      = std::milli;
using centi      = std::centi;
using deci       = std::deci;
using prefixless = unit_prefix<1, 1>;
using deca       = std::deca;
using hecto      = std::hecto;
using kilo       = std::kilo;
using mega       = std::mega;
using giga       = std::giga;
using tera       = std::tera;
using peta       = std::peta;
using exa        = std::exa;

// #if __cplusplus >= 202006L
// using quecto = unit_prefix<std::quecto>;
// using ronto  = unit_prefix<std::ronto>;
// using yocto  = unit_prefix<std::yocto>;
// using zepto  = unit_prefix<std::zepto>;
//
// using zetta  = unit_prefix<std::zetta>;
// using yotta  = unit_prefix<std::yotta>;
// using ronna  = unit_prefix<std::ronna>;
// using quetta = unit_prefix<std::quetta>;
// #endif

} // namespace lmc::units::prefix
