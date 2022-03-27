#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "fstreamExtensions.hpp"

#include "quickLomuto.hpp"

#include "externalMerge.hpp"

int main(int argc, char const *argv[]) {
  std::fstream data("tests/100.bin", data.binary | data.in | data.out);

  if (!data.is_open()) {
    std::cout << "Error during file opening process.\n"
              << std::filesystem::current_path() << '\n';
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  mergeSort<short>(data);
  std::chrono::duration<double, std::milli> duration =
      std::chrono::high_resolution_clock::now() - start;
  std::cout << duration.count() << " ms\n";

  return 0;
}
