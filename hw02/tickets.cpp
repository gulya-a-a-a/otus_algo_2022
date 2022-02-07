#include <iostream>

int main(int argc, char const *argv[])
{
    int maxNumber = 1000;
    unsigned int count = 0;

    for (int leftSide = 0; leftSide < maxNumber; leftSide++)
    {
        unsigned int leftSum = (leftSide / 100) + (leftSide / 10) % 10 + (leftSide % 10);
        for (int rightSide = 0; rightSide < maxNumber; rightSide++)
        {
            unsigned int rightSum = (rightSide / 100) + (rightSide / 10) % 10 + (rightSide % 10);
            if (leftSum == rightSum)
            {
                count++;
            }
        }
    }
    std::cout << count;
    return 0;
}
