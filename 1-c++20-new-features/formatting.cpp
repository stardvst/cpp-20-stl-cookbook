#include <cstdio>
#include <iostream>
#include <format>

using namespace std;

int main()
{
  auto c_string = "world!";

  printf("Hello %s\n", c_string);
  cout << "Hello " << c_string << endl;

  string who{"everyone"};
  int ival{42};
  double pi{3.14/*std::numbers::pi*/};

  cout << format("Hello {}\n", who);
  cout << format("Integer: {}\n", ival);
  cout << format("PI: {}\n", pi);

  cout << format("Integer + PI: {} + {}\n", ival, pi);
  cout << format("Integer + PI: {0} + {1}\n", ival, pi);
  cout << format("Integer + PI: {1} + {0}\n", ival, pi);

  cout << format("{:.<10}\n", ival);
  cout << format("{:.>10}\n", ival);
  cout << format("{:.^10}\n", ival);

  cout << format("{:.1}\n", pi);
}
