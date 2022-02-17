#include <iostream>
#include <type_traits>
#include <chrono>

#include "../test_module/test_module.hpp"

#include "popcnt1.hpp"
#include "popcnt2.hpp"

#include "king.hpp"
#include "knight.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<FindKnightMovesTask> runner("./0.BITS/2.Bitboard - Knight");
    runner.runTests();
    return 0;
}
