import maths;
import std.core;

using namespace std;

int main()
{
  double f = add(1.23, 4.56);
  int i = add(7, 42);
  string s = add<string>("one", "two");
  cout << "double: " << f << '\n'
       << "int: " << i << '\n'
       << "string: " << s << '\n';
}
