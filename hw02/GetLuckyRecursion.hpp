static size_t count = 0;

/**
 * @brief A recursive way to find the number of lucky tickets.
 * Algorithm complexity: O(10^N)
 *
 * @param  {int} N       : Number of digits in a half of a value.
 * @param  {size_t} sumA : Sum of digits of the left side.
 * @param  {size_t} sumB : Sum of digits of the right side.
 */
void GetLuckyTicketRecursion(int N, size_t sumA, size_t sumB) {
    if (N == 0) {
        if (sumA == sumB)
            count++;
        return;
    }

    for (size_t a = 0; a < 10; a++)
        for (size_t b = 0; b < 10; b++)
            GetLuckyTicketRecursion(N - 1, sumA + a, sumB + b);
}

/**
 * @brief Task class to test solution through selfmade test system.
 */
class GetLuckyRecursionTask : public ITestTask {
public:
    GetLuckyRecursionTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override {
        size_t N{}, expectedResult{}, result{};

        std::ifstream inputFile(m_input);
        std::ifstream outputFile(m_output);

        inputFile >> N;
        outputFile >> expectedResult;

        GetLuckyTicketRecursion(N, 0, 0);
        result = count;

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';

        count = 0;
    }
};