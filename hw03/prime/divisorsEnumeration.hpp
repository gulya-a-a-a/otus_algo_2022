static bool isPrimeDivisors(std::uint32_t value)
{
    for (size_t i = 2; i < value; i++)
    {
        if (value % i == 0)
            return false;
    }
    return true;
}

std::uint32_t countPrimes(std::uint32_t value)
{
    std::uint32_t result{};
    for (size_t i = 2; i <= value; i++)
    {
        if (isPrimeDivisors(i))
            ++result;
    }
    return result;
}

class PrimeByDivisorsCountingTask : public ITestTask
{
public:
    PrimeByDivisorsCountingTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override
    {
        std::ifstream input{m_input}, output{m_output};

        std::uint32_t result{}, expectedResult{};
        std::uint32_t value{};

        input >> value;
        output >> expectedResult;

        result = countPrimes(value);

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};