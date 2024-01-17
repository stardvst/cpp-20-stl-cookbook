#include <iostream>

using namespace std;

int main()
{
  int nums1[]{1, 2, 3, 4, 5};
  auto [a1, b1, c1, d1, e1] = nums1;
  cout << a1 << ' ' << b1 << ' ' << c1 << ' ' << d1 << ' ' << e1 << '\n';

  array<int, 5> nums2{1, 2, 3, 4, 5};
  auto [a2, b2, c2, d2, e2] = nums2;
  cout << a2 << ' ' << b2 << ' ' << c2 << ' ' << d2 << ' ' << e2 << '\n';

  tuple<int, double, string> nums3{1, 2.7, "three"};
  auto [a3, b3, c3] = nums3;
  cout << a3 << ' ' << b3 << ' ' << c3 << '\n';

  struct Things
  {
    int i{};
    double d{};
    string s{};
  };
  Things nums4{1, 2.7, "three"};
  auto [a4, b4, c4] = nums4;
  cout << a4 << ' ' << b4 << ' ' << c4 << '\n';

  auto &[_, changed1, changed2] = nums4;
  changed1 = 3.7;
  changed2 = "four";
  cout << nums4.i << ' ' << nums4.d << ' ' << nums4.s << '\n';
}
