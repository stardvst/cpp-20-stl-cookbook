#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
auto value_of(const T v)
{
  if constexpr (std::is_pointer_v<T>)
  {
    return *v;
  }
  else
  {
    return v;
  }
}

int main()
{
  int x{47};
  int *y{&x};
  cout << "value of x is " << value_of(x) << '\n';
  cout << "value of y is " << value_of(y) << '\n';
}
