std::array<int, asciiAlphabetLength> badCharShift(std::string_view pattern) {
  std::array<int, asciiAlphabetLength> result{};

  for (int i = 0; i < asciiAlphabetLength; i++) {
    result[i] = pattern.length();
  }

  for (int i = 0; i < static_cast<int>(pattern.length() - 1); i++) {
    result[pattern[i]] = pattern.length() - i - 1;
  }

  return result;
}

bool isPrefix(std::string_view pattern, int pos) {

  for (int i = pos, j = 0; i < pattern.length(); ++i, ++j)
    if (pattern[i] != pattern[j])
      return false;

  return true;
}

size_t suffixLength(std::string_view pattern, int pos) {
  int i = 0;
  while (pattern[pos - i] == pattern[pattern.length() - 1 - i] && i <= pos) {
    ++i;
  }
  return i;
}

std::vector<int> goodSuffixTable(std::string_view pattern) {

  size_t patternLength = pattern.length();
  std::vector<int> result(patternLength);

  int lastPrefixIndex = patternLength;

  for (int p = patternLength; p > 0; --p) {
    if (isPrefix(pattern, p))
      lastPrefixIndex = p;

    result[patternLength - p] = lastPrefixIndex - p + patternLength;
  }

  for (int i = 0; i < patternLength - 1; i++) {
    size_t sLen = suffixLength(pattern, i);
    result[sLen] = patternLength - 1 - i + sLen;
  }

  return result;
}

int boyerMoore(std::string_view text, std::string_view pattern) {

  if (pattern.length() == 0) {
    return 0;
  }

  auto badCharShiftTable = badCharShift(pattern);
  auto goodSuffixShiftTable = goodSuffixTable(pattern);

  for (int i = pattern.length() - 1, j; i < text.length();) {
    for (j = pattern.length() - 1; pattern[j] == text[i]; --i, --j)
      if (j == 0)
        return i;

    i += std::max(goodSuffixShiftTable[pattern.length() - 1 - j],
                  badCharShiftTable[text[i]]);
  }

  return -1;
}