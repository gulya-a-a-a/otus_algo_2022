#include "swap.hpp"

#include <cmath>

template <typename T>
void shellSort(std::vector<T> &arr)
{
    auto N = arr.size();
    for (int step = N / 2; step > 0; step /= 2)
    {
        for (int i = 0; i + step < N; ++i)
        {
            int j = i + step;
            int key = arr[j];
            while (j - step >= 0 && arr[j - step] > key)
            {
                arr[j] = arr[j - step];
                j -= step;
            }
            arr[j] = key;
        }
    }
}

template <typename T>
void shellSortHibbard(std::vector<T> &arr)
{
    auto N = arr.size();
    int k = std::log2(N);
    for (int step = std::pow(2, k) - 1; step > 0;
         --k, step = std::pow(2, k) - 1)
    {
        for (int i = 0; i + step < N; ++i)
        {
            int j = i + step;
            int key = arr[j];
            while (j - step >= 0 && arr[j - step] > key)
            {
                arr[j] = arr[j - step];
                j -= step;
            }
            arr[j] = key;
        }
    }
}

template <typename T>
void shellSortPapernov(std::vector<T> &arr)
{
    auto N = arr.size();
    int k = std::log2(N);
    for (int step = std::pow(2, k) + 1; step > 1;
         --k, step = std::pow(2, k) + 1)
    {
        if (step == 2)
        {
            step = 1;
        }

        for (int i = 0; i + step < N; ++i)
        {
            int j = i + step;
            int key = arr[j];
            while (j - step >= 0 && arr[j - step] > key)
            {
                arr[j] = arr[j - step];
                j -= step;
            }
            arr[j] = key;
        }
    }
}