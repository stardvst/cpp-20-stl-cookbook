#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void print_vector(const auto &c)
{
  cout << "size: " << c.size() << '\n';
  for (const auto &e : c)
    cout << e << ' ';
  cout << '\n';
}

void print_map(const auto &c)
{
  cout << "size: " << c.size() << '\n';
  for (const auto &[k, v] : c)
    cout << k << "->" << v << '\n';
}

int main()
{
  vector v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_vector(v);

  std::erase(v, 5);
  print_vector(v);

  std::erase_if(v, [](const auto &v)
                { return v % 2 == 1; });
  print_vector(v);

  std::unordered_map<int, int> m;
  m[1] = 1;
  m[2] = 2;
  m[3] = 3;
  m[4] = 4;
  print_map(m);

  std::erase_if(m, [](const auto &p)
                { return p.first % 2 == 1; });
  print_map(m);
}
