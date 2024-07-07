#include "library/algebra/monoid/Concepts.hpp"

#pragma once

template <class G>
concept group = monoid<G> and requires(typename G::value_type x) {
    { G::inverse(x) } -> std::same_as<typename G::value_type>;
};

// todo : able_group