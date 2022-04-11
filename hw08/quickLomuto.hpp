#include "swap.hpp"

template <typename T>
int partitionLomuto(int p, int r, std::vector<T> &arr)
{
    T X = arr[r];
    int i = p - 1;
    for (int j = p; j < r; ++j)
    {
        if (arr[j] <= X)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

template <typename T>
void quickSortLomuto(int p, int r, std::vector<T> &arr)
{
    if (p < r)
    {
        int q = partitionLomuto(p, r, arr);
        quickSortLomuto(p, q - 1, arr);
        quickSortLomuto(q + 1, r, arr);
    }
}

template <typename T>
void quickSortLomuto(std::vector<T> &arr)
{
    quickSortLomuto(0, arr.size() - 1, arr);
}