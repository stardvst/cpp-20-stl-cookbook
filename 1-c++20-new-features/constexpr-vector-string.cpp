#include <vector>
#include <string>
#include <numeric>

using namespace std;

constexpr auto use_string_size()
{
  string str{"text"};
  return str.size(); // size() is constexpr-qualified
}

constexpr auto use_vector()
{
  vector<int> vec{1, 2, 3, 4, 5};
  return vec;
}

constexpr auto use_vector_accum()
{
  vector<int> vec{1, 2, 3, 4, 5};
  return accumulate(begin(vec), end(vec), 0);
}

int main()
{
  // constexpr auto vec = use_vector();
  // return vec[0]; // error: memory was allocted during constant evaluation

  constexpr auto str_size = use_string_size();
  constexpr auto vec_size = use_vector().size();
  constexpr auto accum = use_vector_accum();
  return str_size + vec_size + accum;
}
