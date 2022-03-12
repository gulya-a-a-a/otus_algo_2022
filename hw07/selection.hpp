#include "swap.hpp"

template <typename T>
void selectionSort(std::vector<T> &arr)
{
    size_t indexOfMax = 0;
    for (size_t i = arr.size(); i > 1; --i)
    {
        indexOfMax = 0;

        for (size_t j = 0; j < i; ++j)
        {
            if (arr[j] > arr[indexOfMax])
                indexOfMax = j;
        }
        swap(arr[indexOfMax], arr[i - 1]);
    }
}