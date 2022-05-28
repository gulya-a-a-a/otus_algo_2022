#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <string_view>
#include <vector>

static const size_t asciiAlphabetLength = 128;

#include "boyer_moore.hpp"
#include "substring_search.hpp"

struct StringTestData {
  std::string_view text;
  std::string_view pattern;
  int result;
};

static std::array<StringTestData, 8UL> testData{
    {{"ABC", "BCA", -1},
     {"STROSTRING", "STRING", 4},
     {"ABC", "ABC", 0},
     {"KOOLOOKOLOKOL", "KOLOKOL", 6},
     {"AAAAAAAAAAAA", "BAAAAAA", -1},
     {"AAAAABAAAAAA", "BAAAAAA", 5},
     {"AAAAAAAAAAAA", "AAAAAAB", -1},
     {"AAAAAAAAAAAB", "AAAAAAB", 5}}};

int main(int argc, char const *argv[]) {
  auto &tmp = testData;

  for (auto &&test : testData) {
    assert(bruteForce(test.text, test.pattern) == test.result);
    assert(prefixShift(test.text, test.pattern) == test.result);
    assert(suffixShift(test.text, test.pattern) == test.result);
    assert(boyerMoore(test.text, test.pattern) == test.result);
  }

  return EXIT_SUCCESS;
}
