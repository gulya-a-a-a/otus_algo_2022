#ifndef SWAP_H
#define SWAP_H

template <typename T>
void swap(T &lhs, T &rhs)
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

#endif