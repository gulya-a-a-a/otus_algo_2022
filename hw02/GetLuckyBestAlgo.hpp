#include <vector>

/**
 * @brief The best way to find the number of lucky tickets.
 * Algorithm complexity: O(N^3)
 *
 * @param  {int} N          : Number of digits in a half of a value.
 * @return {std::uint64_t}  : Number of lucky tickets for N-figure numbers.
 */
std::uint64_t GetLuckyBestAlgo(size_t N) {
    std::uint64_t result{};

    std::vector<std::uint64_t> arrayOfSums = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    for (size_t n = 1; n < N; n++) {

        std::vector<std::uint64_t> oldValues = arrayOfSums;

        arrayOfSums.resize(arrayOfSums.size() + 9);

        for (size_t i = 0; i < arrayOfSums.size(); i++) {
            std::uint64_t newValue{};
            for (size_t j = 0; j < 10; j++) {
                std::int64_t index = i - j;
                if (index < 0 || index >= oldValues.size())
                    continue;

                newValue += oldValues[index];
            }
            arrayOfSums[i] = newValue;
        }
    }

    for (auto sum : arrayOfSums) {
        result += sum * sum;
    }

    return result;
}

/**
 * @brief Task class to test solution through selfmade test system.
 */
class GetLuckyBestAlgoTask : public ITestTask {
public:
    GetLuckyBestAlgoTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override {
        size_t N{}, expectedResult{}, result{};

        std::ifstream inputFile(m_input);
        std::ifstream outputFile(m_output);

        inputFile >> N;
        outputFile >> expectedResult;

        result = GetLuckyBestAlgo(N);

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};