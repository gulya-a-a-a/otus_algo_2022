
int bruteForce(std::string_view text,      // STRONGSTRING
               std::string_view pattern) { // STRING
  size_t t = 0, p = 0;
  while (t <= text.length() - pattern.length()) {
    p = 0;
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

std::array<int, asciiAlphabetLength>
createShiftArray(std::string_view pattern) {
  std::array<int, asciiAlphabetLength> result;

  for (int i = 0; i < asciiAlphabetLength; i++) {
    result[i] = pattern.length();
  }

  for (int i = 0; i < static_cast<int>(pattern.length() - 1); i++) {
    result[pattern[i]] = 1;
  }

  return result;
}

int prefixShift(std::string_view text, std::string_view pattern) {

  auto shift = createShiftArray(pattern);
  int t = 0, p = 0;
  while (t <= text.length() - pattern.length()) {
    p = pattern.length() - 1;
    while (text[t + p] == pattern[p] && p > -1) {
      --p;
    }

    if (p < 0) {
      return t;
    }
    t += shift[text[t + p]];
  }

  return -1;
}

std::array<int, asciiAlphabetLength>
createShiftArrayWithIndent(std::string_view pattern) {
  std::array<int, asciiAlphabetLength> result;

  for (int i = 0; i < asciiAlphabetLength; i++) {
    result[i] = pattern.length();
  }
  for (int i = 0; i < static_cast<int>(pattern.length() - 1); i++) {
    result[pattern[i]] = pattern.length() - i - 1;
  }

  return result;
}

int suffixShift(std::string_view text, std::string_view pattern) {
  auto shift = createShiftArrayWithIndent(pattern);

  int t = 0, p = 0;
  while (t <= text.length() - pattern.length()) {
    p = pattern.length() - 1;
    while (text[t + p] == pattern[p] && p > -1) {
      --p;
    }

    if (p < 0) {
      return t;
    }
    t += shift[text[t + pattern.length() - 1]];
  }

  return -1;
}