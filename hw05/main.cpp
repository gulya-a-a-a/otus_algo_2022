#include <iostream>
#include <cstring>

#include "SingleArray.hpp"
#include "VectorArray.hpp"
#include "FactoryArray.hpp"

template <typename T>
void printArray(IArray<T> &array)
{
    for (size_t i = 0; i < array.size(); i++)
        std::cout << array.get(i) << ' ';

    std::cout << '\n';
}

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

    factorArray.put(321, 0);
    printArray(factorArray);

    std::cout << factorArray.del(5) << '\n';
    printArray(factorArray);
    return 0;
}
