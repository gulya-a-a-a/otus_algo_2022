#include "IArray.hpp"

template <typename T, int vector = 10>
class VectorArray : public IArray<T>
{
public:
    VectorArray() : mSize{0}, mCapacity{vector},
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

protected:
    void resize() override
    {
        mCapacity += vector;
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