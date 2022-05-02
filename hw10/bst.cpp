#include <cassert>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

#include "bst.hpp"

#define CHECK_OPERATION_TIMING(operation)                                      \
  auto start = std::chrono::high_resolution_clock::now();                      \
  operation;                                                                   \
  std::chrono::duration<double, std::milli> duration =                         \
      std::chrono::high_resolution_clock::now() - start;                       \
  std::cout << duration.count() << " ms\n";

/**
 * Lambda to test data insertion into BST.
 * @param  {BST} bst : tree to put data into.
 * @param  {vector} data : array of data to put.
 */
auto putToBst = [](BinarySearchTree<std::uint16_t, int> &bst,
                   std::vector<std::uint16_t> &data) {
  int value = 0;
  for (auto i : data) {
    bst.insert(std::move(i), value++);
  }
};

/**
 * Lambda to test data search in BST.
 * @param  {BST} bst : Search tree.
 * @param  {std::uint32_t} numberOfSearches : Number of searches to make.
 */
auto searchInBst = [](BinarySearchTree<std::uint16_t, int> &bst,
                      std::uint32_t numberOfSearches) {
  std::uint32_t numberOfFound{};

  for (size_t i = 0; i < numberOfSearches; i++) {
    std::srand(time(nullptr));
    short valueToSearch = std::rand() % std::numeric_limits<short>::max();
    auto foundNode = bst.getNode(valueToSearch);
    if (foundNode != nullptr) {
      ++numberOfFound;
    }
  }
};

/**
 * Lambda to test data removing from BST.
 * @param  {BST} bst : tree to remove data.
 * @param  {std::uint32_t} numberOfRemoved : Number of values to remove.
 */
auto removeFromBst = [](BinarySearchTree<std::uint16_t, int> &bst,
                        std::uint32_t numberOfRemoved) {
  for (size_t i = 0; i < numberOfRemoved; i++) {
    short keyToRemove = std::rand() % std::numeric_limits<short>::max();
    bst.remove(keyToRemove);
  }
};

static const std::uint32_t fileSize = 100000;

void checkBST(const char *fileName) {

  std::fstream randomData(fileName, randomData.binary | randomData.in);

  if (!randomData.is_open()) {
    std::cout << "An error occured while opening the file: "
              << std::filesystem::current_path() << fileName << '\n';
    return;
  }

  std::vector<std::uint16_t> values(fileSize);

  randomData.read(reinterpret_cast<char *>(values.data()),
                  fileSize * sizeof(std::uint16_t));

  BinarySearchTree<std::uint16_t, int> bst;

  {
    std::cout << "Random values were put in:\t";
    CHECK_OPERATION_TIMING(putToBst(bst, values));
  }
  {
    std::cout << "Random values were found in:\t";
    CHECK_OPERATION_TIMING(searchInBst(bst, fileSize / 10));
  }
  {
    std::cout << "Random values were removed in:\t";
    CHECK_OPERATION_TIMING(removeFromBst(bst, fileSize / 10));
  }
}

int main(int argc, char const *argv[]) {

  char fileName[32]{};

  std::sprintf(fileName, "tests/%d_random.bin", fileSize);

  checkBST(fileName);

  std::sprintf(fileName, "tests/%d_asc.bin", fileSize);

  checkBST(fileName);

  return EXIT_SUCCESS;
}
