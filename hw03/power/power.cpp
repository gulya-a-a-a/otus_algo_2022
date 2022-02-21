#include <iostream>
#include <cmath>
#include <iomanip>
#include "../../test_module/test_module.hpp"

#include "iterative.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<IterativePowerTask> runner("./3.Power/");
    runner.runTests();
    return 0;
}
