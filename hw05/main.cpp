#include <iostream>
#include <cstring>

#include "SingleArray.hpp"
#include "VectorArray.hpp"
#include "FactoryArray.hpp"
#include "MatrixArray.hpp"

static const size_t matrixArraySize = 6;

template <typename T>
void printArray(IArray<T> &array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        if ((i % matrixArraySize == 0) && (i > 0))
            std::cout << '\n';
        std::cout << array.get(i) << ' ';
    }

    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    SingleArray<int> array;
    VectorArray<int, 30> vectorArray;
    FactorArray<int> factorArray;

    MatrixArray<int, matrixArraySize> matrixArray;

    std::cout << matrixArray.size() << '\n';

    for (size_t i = 0; i < 92; i++)
    {
        matrixArray.put(i);
    }

    std::cout << matrixArray.size() << '\n';

    matrixArray.put(321, 6);
    matrixArray.put(444, 44);
    printArray(matrixArray);

    std::cout << matrixArray.del(6) << '\n';

    matrixArray.del(7);
    matrixArray.del(18);
    printArray(matrixArray);

    return 0;
}
