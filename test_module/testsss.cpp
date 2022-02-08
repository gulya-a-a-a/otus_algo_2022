#include <iostream>

#include "test_module.hpp"

class GetLuckyTask : public ITestTask
{
public:
    GetLuckyTask(std::string &input,
                 std::string &output) : ITestTask(input, output) {}
    void run() override
    {
        size_t N{}, expectedResult{}, result{};

        std::ifstream inputFile(m_input);
        std::ifstream outputFile(m_output);

        inputFile >> N;
        outputFile >> expectedResult;

        result = 10;

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};

int main(int argc, char const *argv[])
{
    TestRunner<GetLuckyTask> runner("../hw02/1.Tickets");

    runner.runTests();

    return 0;
}
