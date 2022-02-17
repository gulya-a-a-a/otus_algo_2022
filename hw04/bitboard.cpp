#include <iostream>
#include "../test_module/test_module.hpp"

#include "king.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<FindKingMovesTask> runner("./0.BITS/1.Bitboard - King");
    runner.runTests();
    return 0;
}
