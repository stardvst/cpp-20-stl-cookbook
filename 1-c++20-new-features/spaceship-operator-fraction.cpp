#include <compare>
#include <iostream>

struct Frac
{
  constexpr Frac(int a, int b) : n(a), d(b) {}

  constexpr double dbl() const
  {
    return static_cast<double>(n) / static_cast<double>(d);
  }

  constexpr auto operator<=>(const Frac &f) const
  {
    return dbl() <=> f.dbl();
  }

  // it was decided that operator<=> was not a good default implementation for operator==
  // so this needs to be implemented too
  constexpr auto operator==(const Frac &f) const
  {
    return operator<=>(f) == 0;
  }

  long n{};
  long d{};
};

int main()
{
  constexpr Frac a{10, 15}; // 2/3
  constexpr Frac b{2, 3};
  constexpr Frac c{5, 3};

  static_assert(a < c);
  static_assert(c > a);
  static_assert(a == b);
  static_assert(a <= b);
  static_assert(a <= c);
  static_assert(c >= a);
  static_assert(a != c);

  std::cout << "done.\n";
}
