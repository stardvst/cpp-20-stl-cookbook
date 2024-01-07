#include <ranges>
#include <vector>
#include <iostream>

using namespace std;
namespace ranges = std::ranges;
namespace views = std::ranges::views;

void printRange(const string &msg, auto nums)
{
  cout << msg << ": ";
  for (auto v : nums)
    cout << v << ' ';
  cout << '\n';
}

int main()
{
  const vector nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  auto result = ranges::take_view(nums, 5);
  printRange("first 5", result);

  auto resultReversed = nums | views::take(5) | views::reverse;
  printRange("reversed", resultReversed);

  auto resultEvens = nums | views::take(5) | views::filter([](int i)
                                                           { return i % 2 == 0; });
  printRange("evens", resultEvens);

  auto resultTransformed = nums | views::transform([](int i)
                                                   { return i * i; });
  printRange("transformed", resultTransformed);

  vector words{"one", "two", "three", "four", "five"};
  auto wordsReversed = words | views::reverse;
  printRange("words reversed", wordsReversed);

  auto numSeries = views::iota(1, 10);
  printRange("generated numbers", numSeries);

  auto numSeriesLimited = views::iota(1) | views::take(15);
  printRange("generated infinite numbers", numSeriesLimited);

  auto wordsSorted = ranges::sort(views::drop(words, 1));
  //printRange("words sorted", wordsSorted); // doesn't work?
}
