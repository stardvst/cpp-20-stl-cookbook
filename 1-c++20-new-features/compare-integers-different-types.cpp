#include <iostream>
#include <utility>

using namespace std;

int main()
{
  int x{-3};
  unsigned y{7};
  if (x < y)
    cout << "true\n";
  else
    cout << "false\n"; // this is printed

  if (cmp_less(x, y))
    cout << "true\n"; // this is printed
  else
    cout << "false\n";
}
