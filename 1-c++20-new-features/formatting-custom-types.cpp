#include <iostream>
#include <format>

using namespace std;

struct Frac
{
  long n{};
  long d{};
};

template <>
struct std::formatter<Frac>
{
  template <typename ParseContext>
  constexpr auto parse(ParseContext &ctx)
  {
    return ctx.begin();
  }

  template <typename FormatContext>
  auto format(const Frac &f, FormatContext &ctx)
  {
    return format_to(ctx.out(), "{0:d}/{1:d}", f.n, f.d);
  }
};

int main()
{
  Frac f{5, 3};
  cout << format("Frac: {}\n", f);
}
