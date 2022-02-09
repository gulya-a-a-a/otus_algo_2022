#include <fstream>
#include <filesystem>

template <typename ValueType>
struct TestResult
{
    ValueType value;
};

class ITestTask
{
protected:
    std::string m_input, m_output;

public:
    ITestTask(std::string &input,
              std::string &output) : m_input{std::move(input)},
                                     m_output{std::move(output)}
    {
    }

    virtual void run() = 0;
};

template <typename TaskType>
class TestRunner
{
    std::string m_testsPath;

public:
    TestRunner(std::string &&testsPath) : m_testsPath{std::move(testsPath)}
    {
    }

    TestRunner(std::string &testsPath) : m_testsPath{testsPath}
    {
    }

    void runTests()
    {
        size_t testNumber = 0;
        std::stringstream ss;

        while (true)
        {
            ss << m_testsPath << "/test." << testNumber << ".in";
            std::string inputName{ss.str()};

            ss.str("");
            ss << m_testsPath << "/test." << testNumber << ".out";
            std::string outputName{ss.str()};

            if (!std::filesystem::exists(inputName) ||
                !std::filesystem::exists(outputName))
            {
                break;
            }

            std::cout << "Test #" << testNumber << ": ";
            TaskType task(inputName, outputName);

            task.run();

            ++testNumber;
            ss.str("");
            std::cout << '\n';
        }
    }
};