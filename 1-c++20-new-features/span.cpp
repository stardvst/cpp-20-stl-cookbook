#include <span>
#include <iostream>

using namespace std;

template <typename T>
void pspan(span<T> s)
{
  cout << "number of elements: " << s.size() << '\n';
  cout << "size of span: " << s.size_bytes() << '\n';
  cout << "first element: " << s.front() << '\n';
  cout << "last element: " << s.back() << '\n';

  cout << "elements: ";
  for (auto e : s)
    cout << e << ' ';
  cout << '\n';

  cout << "first four elements: ";
  for (auto e : s.first<4>())
    cout << e << ' ';
  cout << '\n';
}

int main()
{
  int carray[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  pspan<int>(carray);
}
