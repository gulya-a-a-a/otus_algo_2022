/**
 * @brief Brute force method to find the number of six-figure lucky tickets.
 *
 * @return {size_t}  : Number of lucky tickets for six-figure numbers.
 */
size_t GetLuckyTicketSixBruteforce() {
    size_t maxNumber = 1000;
    size_t count = 0;

    for (size_t leftSide = 0; leftSide < maxNumber; leftSide++) {

        unsigned int leftSum = (leftSide / 100) + (leftSide / 10) % 10 + (leftSide % 10);

        for (size_t rightSide = 0; rightSide < maxNumber; rightSide++) {

            unsigned int rightSum =
                (rightSide / 100) + (rightSide / 10) % 10 + (rightSide % 10);

            if (leftSum == rightSum) {
                count++;
            }
        }
    }

    return count;
}

/**
 * @brief A task class for testing a solution using a self-made test system.
 */
class GetLuckySixBruteforceTask : public ITestTask {
public:
    GetLuckySixBruteforceTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override {
        size_t N{}, expectedResult{}, result{};

        std::ifstream inputFile(m_input);
        std::ifstream outputFile(m_output);

        inputFile >> N;
        outputFile >> expectedResult;

        result = GetLuckyTicketSixBruteforce();

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};
