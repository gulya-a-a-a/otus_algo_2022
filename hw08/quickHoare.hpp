#include "swap.hpp"

template <typename T>
int partitionHoare(int p, int r, std::vector<T> &arr)
{
    int L = p - 1;
    int R = r + 1;
    T X = arr[r];

    while (true)
    {
        do
        {
            ++L;
        } while (arr[L] < X);

        do
        {
            --R;
        } while (arr[R] > X);

        if (L > R)
            return R;

        swap(arr[L], arr[R]);
    }
}

template <typename T>
void quickSortHoare(int p, int r, std::vector<T> &arr)
{
    if (p < r)
    {
        int q = partitionHoare(p, r, arr);
        quickSortHoare(p, q, arr);
        quickSortHoare(q + 1, r, arr);
    }
}

template <typename T>
void quickSortHoare(std::vector<T> &arr)
{
    quickSortHoare(0, arr.size() - 1, arr);
}