#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <limits>
#include <vector>

#include "fstreamExtensions.hpp"
#include "merge.hpp"

#include "shell.hpp"

#include "bucket.hpp"
#include "externalMerge.hpp"
#include "externalMergeWithShellSort.hpp"

#define CHECK_OPERATION_TIMING(operation)                                      \
  auto start = std::chrono::high_resolution_clock::now();                      \
  operation;                                                                   \
  std::chrono::duration<double, std::milli> duration =                         \
      std::chrono::high_resolution_clock::now() - start;                       \
  std::cout << duration.count() << " ms\n";

int main(int argc, char const *argv[]) {
  size_t fileSize = 1000000;
  std::fstream data("tests/1000000.bin", data.binary | data.in | data.out);

  if (!data.is_open()) {
    std::cout << "Error during file opening process.\n"
              << std::filesystem::current_path() << '\n';
    return EXIT_FAILURE;
  }
  // { CHECK_OPERATION_TIMING(externalMergeSort<unsigned short>(data)); }

  { CHECK_OPERATION_TIMING(mergeSortWithShell<unsigned short>(data)); }

  std::vector<unsigned short> vData(fileSize);
  data.read(reinterpret_cast<char *>(vData.data()), fileSize * sizeof(short));

  { CHECK_OPERATION_TIMING(bucketSort<unsigned short>(vData)); }
  return EXIT_SUCCESS;
}
