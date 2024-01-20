#include <iostream>

using namespace std;

template <typename T>
class Sum
{
public:
  template <typename... Ts>
  Sum(Ts &&...ts) : sum{(ts + ...)} {}
  const T &value() const { return sum; }

private:
  T sum;
};

template <typename... Ts>
Sum(Ts &&...ts) -> Sum<std::common_type_t<Ts...>>;

int main()
{
  Sum sum1{1u, 2.0, 3, 4.0f};
  auto v1 = sum1.value();
  cout << v1 << " is " << typeid(v1).name() << '\n';

  Sum sum2{"abc"s, "def"};
  auto v2 = sum2.value();
  cout << v2 << " is " << typeid(v2).name() << '\n';
}
