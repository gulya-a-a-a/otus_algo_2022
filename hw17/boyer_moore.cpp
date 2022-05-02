#include <array>
#include <cassert>
#include <iostream>

#include "substring_search.hpp"

struct StringTestData {
  std::string_view text;
  std::string_view pattern;
  int result;
};

static std::array<StringTestData, 9UL> testData{
    {{"", "", 0},
     {"ABC", "BCA", -1},
     {"STROSTRING", "STRING", 4},
     {"ABC", "ABC", 0},
     {"KOLOdKOLOKOL", "KOLOKOL", 5},
     {"AAAAAAAAAAAA", "BAAAAAA", -1},
     {"AAAAABAAAAAA", "BAAAAAA", 5},
     {"AAAAAAAAAAAA", "AAAAAAB", -1},
     {"AAAAAAAAAAAB", "AAAAAAB", 5}}};

int main(int argc, char const *argv[]) {
  auto &tmp = testData;

  for (auto &&test : testData) {
    std::cout << test.text << '\n';
    // assert(bruteForce(test.text, test.pattern) == test.result);
    // assert(prefixShift(test.text, test.pattern) == test.result);
    assert(suffixShift(test.text, test.pattern) == test.result);
  }

  return EXIT_SUCCESS;
}
