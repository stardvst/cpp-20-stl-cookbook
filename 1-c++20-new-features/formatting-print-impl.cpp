#include <cstdio>
#include <iostream>
#include <format>

using namespace std;

template <typename... Args>
void print(const string_view fmt_str, Args &&...args)
{
  auto fmt_args{make_format_args(args...)};
  string outstr{vformat(fmt_str, fmt_args)};
  fputs(outstr.c_str(), stdout);
}

int main()
{
  string who{"everyone"};
  int ival{42};
  double pi{3.14 /*std::numbers::pi*/};

  print("Hello {}\n", who);
  print("PI: {}\n", pi);
  print("Hello {1} {0}\n", ival, who);
  print("{:.<10}\n", ival);
  print("{:.1}\n", pi);
}
