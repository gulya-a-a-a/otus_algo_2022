
std::uint64_t findKnightMoves(std::uint8_t position)
{
    std::uint64_t K = 1UL << position,
                  AMask = 0xfefefefefefefefe,
                  BMask = 0xfdfdfdfdfdfdfdfd,
                  GMask = 0xbfbfbfbfbfbfbfbf,
                  HMask = 0x7f7f7f7f7f7f7f7f,
                  Ka = K & AMask,
                  Kab = Ka & BMask,
                  Kh = K & HMask,
                  Kgh = Kh & GMask;

    std::uint64_t result = (Ka << 15) | (Kh << 17) |  // top
                           (Kab << 6) | (Kab >> 10) | // left
                           (Ka >> 17) | (Kh >> 15) |  // bottom
                           (Kgh >> 6) | (Kgh << 10);  // right

    return result;
}

class FindKnightMovesTask : public ITestTask
{
public:
    FindKnightMovesTask(std::string &input, std::string &output)
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

        std::uint64_t result = findKnightMoves(position);

        auto resultedNumberOfMoves = popcnt2(result);

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