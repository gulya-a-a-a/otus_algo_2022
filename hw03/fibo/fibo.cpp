#include <iostream>

#include "../../test_module/test_module.hpp"

#include "iterative.hpp"
#include "recursive.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<IterativeFiboTask> runner("./4.Fibo");
    runner.runTests();
    return 0;
}
