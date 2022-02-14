#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

cpp_int iterativeFibo(std::int64_t index)
{
    if (index <= 1)
        return index;

    cpp_int currentValue{0}, nextValue{1}, result{};
    for (std::int64_t i = 2; i <= index; ++i)
    {
        result = currentValue + nextValue;
        currentValue = nextValue;
        nextValue = result;
    }
    return result;
}

class IterativeFiboTask : public ITestTask
{
public:
    IterativeFiboTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override
    {
        std::ifstream input{m_input}, output{m_output};

        cpp_int result{}, expectedResult{};
        std::int64_t index{};

        input >> index;
        output >> expectedResult;

        result = iterativeFibo(index);

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};