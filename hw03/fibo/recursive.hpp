#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

cpp_int recursiveFibo(std::int64_t index)
{
    if (index <= 1)
        return index;
    return recursiveFibo(index - 1) + recursiveFibo(index - 2);
}

class RecursiveFiboTask : public ITestTask
{
public:
    RecursiveFiboTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override
    {
        std::ifstream input{m_input}, output{m_output};

        cpp_int result{}, expectedResult{};
        std::int64_t index{};

        input >> index;
        output >> expectedResult;

        result = recursiveFibo(index);

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};