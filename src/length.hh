#pragma once

#include "unit_container.hh"

namespace lmc::units::length
{

namespace definition
{
using length_dimension = dimensional::dimensional_vector<
    dimensional::length<1>,
    dimensional::mass<1>,
    dimensional::time<1>,
    dimensional::current<1>,
    dimensional::temperature<1>,
    dimensional::luminosity<1>,
    dimensional::substance<1>>;

using meters
    = unit_definition<length_dimension, base_unit_prefix, base_unit_ratio>;

using feet = unit_definition<
    length_dimension,
    base_unit_prefix,
    unit_ratio_wrt<381, 1250, meters>>;
} // namespace definition

using meters = unit_container<definition::meters>;
using feet   = unit_container<definition::feet>;

} // namespace lmc::units::length
