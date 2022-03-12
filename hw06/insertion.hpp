
template <typename T>
void insertionSort(std::vector<T> &arr)
{
    size_t N = arr.size();
    for (size_t i = 0; i < N; i++)
    {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1])
        {
            swap(arr[j], arr[j - 1]);
            --j;
        }
    }
}

template <typename T>
void insertionSortImproved(std::vector<T> &arr)
{
    size_t N = arr.size();
    for (size_t i = 2; i < N; i++)
    {
        T key = arr[i];
        int j = i - 1;
        while (j > -1 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

template <typename T>
int binarySearch(std::vector<T> &arr, T value, int lowIndex, int highIndex)
{
    while (lowIndex <= highIndex)
    {
        int mid = lowIndex + (highIndex - lowIndex) / 2;
        if (arr[mid] == value)
        {
            return mid + 1;
        }
        else if (arr[mid] > value)
        {
            highIndex = mid - 1;
        }
        else
        {
            lowIndex = mid + 1;
        }
    }

    return lowIndex;
}

template <typename T>
void insertionSortBinary(std::vector<T> &arr)
{
    size_t N = arr.size();
    for (size_t i = 1; i < N; i++)
    {
        T key = arr[i];
        int j = (i - 1);

        int index = binarySearch(arr, key, 0, j);

        while (j >= index)
        {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}