#include "swap.hpp"

template <typename T>
void merge(int p, int q, int r, std::vector<T> &arr, std::vector<T> &tmp)
{
    int a = p;
    int b = q + 1;
    int m = p;
    while (a <= q && b <= r)
    {
        if (arr[a] <= arr[b])
            tmp[m++] = arr[a++];
        else
            tmp[m++] = arr[b++];
    }
    while (a <= q)
        tmp[m++] = arr[a++];
    while (b <= r)
        tmp[m++] = arr[b++];

    for (int i = p; i < r + 1; ++i)
        arr[i] = tmp[i];
}

template <typename T>
void mergeSort(int p, int r, std::vector<T> &arr, std::vector<T> &tmp)
{
    if (p >= r)
        return;
    int q = (p + r) / 2;
    mergeSort(p, q, arr, tmp);
    mergeSort(q + 1, r, arr, tmp);
    merge(p, q, r, arr, tmp);
}

template <typename T>
void mergeSort(std::vector<T> &arr)
{
    std::vector<T> tmp(arr.size());
    mergeSort(0, arr.size() - 1, arr, tmp);
}
