#include <iostream>

using namespace std;

template <typename T>
constexpr bool is_greater_than_byte{sizeof(T) > 1};

template <typename T>
concept Numeric = is_greater_than_byte<T> && (is_integral_v<T> || is_floating_point_v<T>);

template <typename T>
  requires Numeric<T>
T add42_0(const T &arg)
{
  return arg + 42;
}

template <Numeric T>
T add42_1(const T &arg)
{
  return arg + 42;
}

template <typename T>
T add42_2(const T &arg)
  requires Numeric<T>
{
  return arg + 42;
}

auto add42_3(Numeric auto &arg)
{
  return arg + 42;
}

int main()
{
  const char *n = "7";

  cout << "won't compile: " << add42_0(n) << '\n';
  cout << "won't compile: " << add42_1(n) << '\n';
  cout << "won't compile: " << add42_2(n) << '\n';
  cout << "won't compile: " << add42_3(n) << '\n';
}
