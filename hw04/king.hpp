
std::uint64_t findKingMoves(std::uint8_t position)
{
    std::uint64_t K = 1UL << position,
                  AMask = 0xfefefefefefefefe,
                  HMask = 0x7f7f7f7f7f7f7f7f,
                  Ka = K & AMask,
                  Kh = K & HMask;

    std::uint64_t result = (Ka << 7) | (K << 8) | (Kh << 9) |
                           (Ka >> 1) | (Kh << 1) |
                           (Ka >> 9) | (K >> 8) | (Kh >> 7);

    return result;
}

class FindKingMovesTask : public ITestTask
{
public:
    FindKingMovesTask(std::string &input, std::string &output)
        : ITestTask(input, output) {}

    void run()
    {

        std::ifstream input{m_input},
            output{m_output};

        std::uint16_t position{};
        std::uint64_t expectedResult{},
            expectedNumberOfMoves{};

        input >> position;
        output >> expectedNumberOfMoves >> expectedResult;

        std::uint64_t result = findKingMoves(position);

        auto start = std::chrono::steady_clock::now();
        auto resultedNumberOfMoves = popcnt2(result);
        auto time = std::chrono::steady_clock::now() - start;
        std::cout << "\nTime: " << time.count() << " ns\n";

        std::cout
            << ((expectedResult == result) && (expectedNumberOfMoves == resultedNumberOfMoves)
                    ? "Passed"
                    : "Failed")
            << '\n'

            << "Expected bits count: " << expectedNumberOfMoves << '\n'
            << "Received bits count: " << resultedNumberOfMoves << '\n'

            << "Expected value: " << expectedResult << '\n'
            << "Received value: " << result << '\n';
    }
};