#include "IArray.hpp"

template <typename T>
class SingleArray : public IArray<T>
{
public:
    SingleArray() : mSize{0}, mData{nullptr}
    {
    }

    size_t size() const override
    {
        return mSize;
    }

    T get(int index) const override
    {
        return mData[index];
    }

    void put(T &&item) override
    {
        resize();
        mData[size() - 1] = item;
    }

    void resize() override
    {
        auto newData = new T[size() + 1];
        if (!IArray<T>::isEmpty())
        {
            std::memcpy(newData, mData, size() * sizeof(T));
            delete[] mData;
        }
        mData = newData;
        ++mSize;
    }

private:
    size_t mSize;
    T *mData;
};