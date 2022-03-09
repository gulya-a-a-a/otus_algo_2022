#include "IArray.hpp"

template <typename T, size_t rowSize = 100>
class MatrixArray : public IArray<T>
{
    const size_t lastIndexInArray = rowSize - 1;

public:
    MatrixArray() : mColCount{1}, mRowCount{0}
    {
        mData = new T *[1];
        mData[0] = new T[rowSize];
    }

    size_t size() const override
    {
        return (mColCount - 1) * rowSize + mRowCount;
    };

    T get(int index) const override
    {
        return mData[index / rowSize][index % rowSize];
    };

    void put(T &&item) override
    {
        if (mRowCount >= rowSize)
            resize();

        mData[mColCount - 1][mRowCount] = item;
        ++mRowCount;
    };

    void put(T &&item, int index) override
    {
        if (mRowCount + 1 >= rowSize)
            resize();

        int arrayNumber = index / rowSize;
        int numberInArray = index % rowSize;

        for (size_t i = mColCount - 1; i > arrayNumber; --i)
        {
            std::memmove(&mData[i][1], &mData[i][0], (rowSize - 1) * sizeof(T));
            mData[i][0] = mData[i - 1][lastIndexInArray];
        }

        std::memmove(&mData[arrayNumber][numberInArray + 1], &mData[arrayNumber][numberInArray],
                     (rowSize - numberInArray - 1) * sizeof(T));
        mData[arrayNumber][numberInArray] = item;

        ++mRowCount;
    };

    T del(int index) override
    {
        int arrayNumber = index / rowSize;
        int numberInArray = index % rowSize;

        T result = mData[arrayNumber][numberInArray];

        std::memmove(&mData[arrayNumber][numberInArray], &mData[arrayNumber][numberInArray + 1],
                     (rowSize - numberInArray - 1) * sizeof(T));

        for (size_t i = arrayNumber + 1; i < mColCount; i++)
        {
            mData[i - 1][lastIndexInArray] = mData[i][0];
            std::memmove(&mData[i][0], &mData[i][1], (rowSize - 1) * sizeof(T));
        }

        if (mRowCount == 0)
        {
            mRowCount = lastIndexInArray;
            --mColCount;
        }
        else
        {
            --mRowCount;
        }

        return result;
    };

protected:
    void resize() override
    {
        T **newData = new T *[mColCount + 1];

        std::memcpy(newData, mData, mColCount * sizeof(T *));
        delete[] mData;

        mData = newData;
        ++mColCount;
        mRowCount = 0;

        mData[mColCount - 1] = new T[rowSize];
    };

private:
    size_t mColCount, mRowCount;
    T **mData;
};