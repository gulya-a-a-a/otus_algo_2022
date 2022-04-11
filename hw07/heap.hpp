template <typename T>
void heapify(size_t root, size_t size, std::vector<T> &arr)
{
    size_t L = 2 * root + 1;
    size_t R = 2 * root + 2;

    size_t X = root;
    if (L < size && arr[L] > arr[X])
        X = L;

    if (R < size && arr[R] > arr[X])
        X = R;

    if (X == root)
        return;

    swap(arr[X], arr[root]);
    heapify(X, size, arr);
}

template <typename T>
void heapSort(std::vector<T> &arr)
{
    for (int root = arr.size() / 2 - 1; root >= 0; --root)
    {
        heapify(root, arr.size(), arr);
    }

    for (size_t i = arr.size() - 1; i > 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(0, i, arr);
    }
}