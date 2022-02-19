#include <iostream>
#include <type_traits>
#include <chrono>

#include "../test_module/test_module.hpp"

#include "popcnt1.hpp"
#include "popcnt2.hpp"
#include "popcnt_cache.hpp"

#include "king.hpp"
#include "knight.hpp"
#include "rook.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<FindRookMovesTask> runner("./0.BITS/3.Bitboard - Rook");
    runner.runTests();
    return 0;
}
