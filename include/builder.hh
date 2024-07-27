#pragma once

#include <wither/units/units.hh>

namespace units::make
{

template <
    impl::magnitude_cpt mag_t = impl::basic<impl::no_dimension, long double>>
struct base
{
    using value = mag_t;

    template <impl::magnitude_cpt mag_u>
    using for_every = base<impl::multiply<value, mag_u>>;

    template <impl::magnitude_cpt mag_u>
    using per = base<impl::divide<value, mag_u>>;

    template <impl::util::ratio_cpt ratio_t>
    using with_a_factor_of = impl::swap_ratio<value, ratio_t>;

    template <impl::util::ratio_cpt ratio_t>
    using with_a_prefix_of = impl::swap_prefix<value, ratio_t>;

    template <impl::util::ratio_cpt ratio_t>
    using with_a_delta_of = impl::swap_delta<value, ratio_t>;
};

} // namespace units::make
