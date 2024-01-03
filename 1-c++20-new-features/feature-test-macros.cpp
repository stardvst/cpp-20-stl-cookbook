#include <version>
#include <iostream>

using namespace std;

int main()
{
#ifdef __cpp_lib_three_way_comparison
#include <compare>
  cout << "Including <compare>...\n";
#else
  cout << "Shapeship has not landed yet\n";
#endif

#if __has_include(<compare>)
#include <compare>
  cout << "Including <compare>...\n";
#else
  cout << "Shapeship has not landed yet\n";
#endif

#ifdef __cpp_constexpr
  cout << "__cpp_constexpr: " << __cpp_constexpr << '\n';
#else
  cout << "constexpr has not landed yet\n";
#endif
}
