
template <typename T>
void bubbleSort(std::vector<T> &arr)
{
    size_t N = arr.size();
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

template <typename T>
void bubbleSortImproved(std::vector<T> &arr)
{
    size_t N = arr.size();
    bool swapCalled = false;
    for (size_t i = 0; i < N; i++)
    {
        swapCalled = false;
        for (size_t j = 0; j < N - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCalled = true;
            }
        }

        if (!swapCalled)
            break;
    }
}