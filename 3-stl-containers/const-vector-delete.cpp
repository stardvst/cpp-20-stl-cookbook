#include <iostream>

using namespace std;

void print_vector(const auto &c)
{
  cout << "size: " << c.size() << '\n';
  for (const auto &e : c)
    cout << e << ' ';
  cout << '\n';
}

template <typename T>
void quick_delete(T &c, size_t idx)
{
  if (idx < c.size())
  {
    c[idx] = std::move(c.back());
    c.pop_back();
  }
}

template <typename T>
void quick_delete(T &c, typename T::iterator it)
{
  if (it < c.end())
  {
    *it = std::move(c.back());
    c.pop_back();
  }
}

int main()
{
  vector v{1, 2, 3, 4, 5, 6, 7, 8, 9};
  print_vector(v);

  quick_delete(v, 4);
  print_vector(v);

  auto it = std::ranges::find(v, 2);
  quick_delete(v, it);
  print_vector(v);
}
