#include <iostream>

#include "substring_search.hpp"

int main(int argc, char const *argv[]) {
  std::string text{"STRONGSTRING"};
  std::string pattern{"STRING"};

  std::cout << bruteForceSubstringSearch(text, pattern) << '\n';
  return EXIT_SUCCESS;
}
