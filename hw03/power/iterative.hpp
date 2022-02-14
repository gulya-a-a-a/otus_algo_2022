double iterativePower(double value, std::uint64_t power)
{
    double result{1};
    for (size_t i = 0; i < power; ++i)
    {
        result *= value;
    }
    return result;
}

class IterativePowerTask : public ITestTask
{
public:
    IterativePowerTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override
    {
        std::ifstream input{m_input}, output{m_output};

        double result{}, expectedResult{},
            value{}, epsilon{0.000000000005};
        std::uint64_t power{};

        input >> value >> power;
        output >> expectedResult;

        result = iterativePower(value, power);
        auto difference = (expectedResult - result);

        std::cout << std::setprecision(13) << (difference > epsilon ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};