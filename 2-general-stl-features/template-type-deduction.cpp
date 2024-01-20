#include <iostream>

using namespace std;

template <typename T>
const char *f(const T &a)
{
  return typeid(a).name();
}

template <typename T1, typename T2, typename T3>
class Types
{
public:
  explicit Types(T1 t1, T2 t2, T3 t3) : v1(t1), v2(t2), v3(t3) {}
  void print() const
  {
    cout << v1 << ", " << v2 << ", " << v3 << '\n';
  }

private:
  T1 v1{};
  T2 v2{};
  T3 v3{};
};

int main()
{
  cout << "T is " << f(47) << '\n';
  cout << "T is " << f(47L) << '\n';
  cout << "T is " << f(47.0) << '\n';
  cout << "T is " << f("47") << '\n';
  cout << "T is " << f("47"s) << '\n';

  Types types{1, 47.0, "three"};
  types.print();
}
