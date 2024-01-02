#include <compare>
#include <iostream>

struct Num
{
  constexpr Num(int a) : a(a) {}
  auto operator<=>(const Num &) const = default;

  int a{};
};

int main()
{
  constexpr Num a{7};
  constexpr Num b{7};
  constexpr Num c{42};

  static_assert(a < c);
  static_assert(c > a);
  static_assert(a == b);
  static_assert(a <= b);
  static_assert(a <= c);
  static_assert(c >= a);
  static_assert(a != c);
  static_assert(a < 42); // a <=> 42 < 0

  std::cout << "done.\n";
}
