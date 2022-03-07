#include "IArray.hpp"

template <typename T, int factor = 2>
class FactorArray : public IArray<T>
{
public:
    FactorArray() : mSize{0}, mCapacity{10},
                    mData{new T[mCapacity]}
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
        if (size() == mCapacity)
            resize();

        mData[size()] = item;
        ++mSize;
    }

    void put(T &&item, int index) override
    {
        if (size() == mCapacity)
            resize();

        std::memmove(&mData[index + 1], &mData[index], (size() - index) * sizeof(T));
        mData[index] = item;

        ++mSize;
    }

    T del(int index) override
    {
        T result = mData[index];

        std::memmove(&mData[index], &mData[index + 1], (size() - index) * sizeof(T));
        --mSize;

        return result;
    }

protected:
    void resize() override
    {
        mCapacity *= factor;
        auto newData = new T[mCapacity];
        if (!IArray<T>::isEmpty())
        {
            std::memcpy(newData, mData, size() * sizeof(T));
            delete[] mData;
        }
        mData = newData;
    }

private:
    size_t mSize;
    size_t mCapacity;
    T *mData;
};