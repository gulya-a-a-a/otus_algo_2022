
std::uint64_t findRookMoves(std::uint16_t position)
{
    std::uint32_t rowNumber = static_cast<std::uint32_t>(position / 8UL),
                  rowStartPosition = rowNumber * 8UL,
                  columnNumber = position - rowStartPosition;

    std::uint64_t K = 1UL << position,
                  rowMask = (0xffUL << rowStartPosition),
                  columnMask{};

    auto bitMask = 1 << columnNumber;
    for (size_t i = 0; i < 8; i++)
    {
        columnMask <<= 8;
        columnMask |= bitMask;
    }

    std::uint64_t result = K ^ (rowMask | columnMask);

    return result;
}

class FindRookMovesTask : public ITestTask
{
public:
    FindRookMovesTask(std::string &input, std::string &output)
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

        std::uint64_t result = findRookMoves(position);

        auto resultedNumberOfMoves = popcnt_cache(result);

        auto testPassed = (expectedResult == result) &&
                          (expectedNumberOfMoves == resultedNumberOfMoves);

        std::cout << "Position: " << position << '\n';

        std::cout << (testPassed ? "Passed"
                                 : "Failed")
                  << "\n\n"

                  << "Expected bits count: " << expectedNumberOfMoves << '\n'
                  << "Received bits count: " << resultedNumberOfMoves << '\n'

                  << "Expected value: " << expectedResult << '\n'
                  << "Received value: " << result << '\n';
    }
};