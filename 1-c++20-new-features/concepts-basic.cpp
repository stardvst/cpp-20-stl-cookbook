#include <iostream>

using namespace std;

template <typename T>
T add42(const T &arg)
{
  return arg + 42;
}

template <typename T>
concept Numeric = is_integral_v<T> || floating_point<T>;

// function templateß
template <typename T>
  requires Numeric<T>
T add42_strict(const T &arg)
{
  return arg + 42;
}

// class template
template <typename T>
  requires Numeric<T>
struct Num
{
  T n;
  Num(T n) : n(n) {}
};

// variable template
template <typename T>
  requires floating_point<T>
T pi = {3.141592653587932385L};

int main()
{
  const char *n = "7";
  cout << "wrong result is '" << add42(n) << "'\n";
  // cout << "won't compile: " << add42_strict(n) << '\n';

  Num<int> num1{7};
  // Num<std::string> num2{8}; // won't compile

  cout << "correct result is '" << add42(5) << "'\n";
  cout << "num1 is '" << num1.n << "'\n";

  cout << "pi double is '" << pi<double> << "'\n";
  // cout << "won't compile: " << pi<char> << '\n';
}
