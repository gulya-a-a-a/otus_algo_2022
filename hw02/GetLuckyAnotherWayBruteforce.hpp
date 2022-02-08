size_t GetLuckyAnotherWayBruteforce() {

    size_t base = 10, count{};

    for (size_t a1 = 0; a1 < base; a1++) {
        for (size_t a2 = 0; a2 < base; a2++) {
            for (size_t a3 = 0; a3 < base; a3++) {

                size_t a123 = a1 + a2 + a3;

                for (size_t b1 = 0; b1 < base; b1++) {
                    for (size_t b2 = 0; b2 < base; b2++) {

                        int b3 = a123 - (b1 + b2);

                        if (b3 < 10 && b3 >= 0) {
                            ++count;
                        }
                    }
                }
            }
        }
    }
    return count;
}

class GetLuckyAnotherWayBruteforceTask : public ITestTask {

  public:
    GetLuckyAnotherWayBruteforceTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run() override {
        size_t N{}, expectedResult{}, result{};

        std::ifstream inputFile(m_input);
        std::ifstream outputFile(m_output);

        inputFile >> N;
        outputFile >> expectedResult;

        result = GetLuckyAnotherWayBruteforce();

        std::cout << (expectedResult != result ? "Failed" : "Passed") << '\n'
                  << "Expected: " << expectedResult << '\n'
                  << "Received: " << result << '\n';
    }
};
