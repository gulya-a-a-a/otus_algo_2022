#include <iostream>
#include "../../test_module/test_module.hpp"

#include "divisorsEnumeration.hpp"

int main(int argc, char const *argv[])
{
    TestRunner<PrimeByDivisorsCountingTask> runner("./5.Primes/");
    runner.runTests();
    return 0;
}
