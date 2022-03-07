#include <iostream>
#include <cstring>

#include "SingleArray.hpp"
#include "VectorArray.hpp"
#include "FactoryArray.hpp"

int main(int argc, char const *argv[])
{
    SingleArray<int> array;
    VectorArray<int, 30> vectorArray;
    FactorArray<int> factorArray;

    std::cout << factorArray.size() << '\n';

    for (size_t i = 0; i < 100; i++)
    {
        factorArray.put(i);
    }

    std::cout << factorArray.size() << '\n';

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << factorArray.get(i) << ' ';
    }
    std::cout << '\n';

    return 0;
}
