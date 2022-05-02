#include <string_view>

int bruteForceSubstringSearch(std::string_view text,      // STRONGSTRING
                              std::string_view pattern) { // STRING
  size_t t = 0, p = 0;
  while (t <= text.length() - pattern.length()) {
    while ((text[t + p] == pattern[p]) && (p < pattern.length())) {
      ++p;
    }

    if (p == pattern.length()) {
      return t;
    }
    t++;
  }
  return -1;
}