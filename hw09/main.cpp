#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

#include "fstreamExtensions.hpp"
#include "merge.hpp"

#include "shell.hpp"

#include "externalMerge.hpp"
#include "externalMergeWithShellSort.hpp"

int main(int argc, char const *argv[]) {
  std::fstream data("tests/1000000.bin", data.binary | data.in | data.out);

  if (!data.is_open()) {
    std::cout << "Error during file opening process.\n"
              << std::filesystem::current_path() << '\n';
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  mergeSortWithShell<short>(data);
  std::chrono::duration<double, std::milli> duration =
      std::chrono::high_resolution_clock::now() - start;
  std::cout << duration.count() << " ms\n";

  return 0;
}
