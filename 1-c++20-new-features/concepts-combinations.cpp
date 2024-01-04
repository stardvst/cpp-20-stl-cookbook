#include <concepts>

using namespace std;

// constraint conjunction
template <typename T>
concept SignedAndIntegral = is_integral_v<T> && is_signed_v<T>;

// constraint disjunction
template <typename T>
concept Numeric = is_integral_v<T> || is_floating_point_v<T>;

// atomic constraint
template <typename T>
concept is_greater_than_byte = sizeof(T) > 1;

// atomic constraint
template <typename T>
concept is_byte = !is_greater_than_byte<T>;
