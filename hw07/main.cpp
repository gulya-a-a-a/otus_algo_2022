#include <vector>
#include <iostream>
#include <cassert>
#include <sstream>
#include <chrono>
#include <fstream>

#include "selection.hpp"
#include "heap.hpp"

template <typename T>
using sortingFunc = void (*)(std::vector<T> &);

static std::vector<sortingFunc<int>> sortings = {
    selectionSort,
    heapSort,
};

int main(int argc, char const *argv[])
{
    for (size_t i = 100; i < 10000000; i *= 10)
    {
        std::cout << '\n';
        std::stringstream ss;
        ss << "tests/" << i << ".txt";
        auto filename = ss.str();
        std::ifstream input{filename};

        std::vector<int> vec{};

        for (std::string line{}; std::getline(input, line);)
        {
            vec.push_back(std::stoi(line));
        }

        for (auto &sorting : sortings)
        {
            std::vector<int> vec2 = vec;
            auto start = std::chrono::high_resolution_clock::now();
            sorting(vec2);
            std::chrono::duration<double, std::milli> duration = std::chrono::high_resolution_clock::now() - start;
            std::cout << duration.count() << " ms\n";
        }
    }

    return EXIT_SUCCESS;
}
