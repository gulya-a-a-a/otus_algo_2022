#ifndef I_ARRAY_H
#define I_ARRAY_H

template <typename T>
class IArray
{
public:
    virtual size_t size() const = 0;

    bool isEmpty() const
    {
        return size() == 0;
    }

    virtual T get(int index) const = 0;

    virtual void put(T &&item) = 0;

    virtual void put(T &&item, int index) = 0;

    virtual T del(int index) = 0;

protected:
    virtual void resize() = 0;
};

#endif