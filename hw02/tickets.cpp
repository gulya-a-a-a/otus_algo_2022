#include "tickets.hpp"

#include "GetLuckyAnotherWayBruteforce.hpp"
#include "GetLuckyBestAlgo.hpp"
#include "GetLuckyRecursion.hpp"
#include "GetLuckySixBruteforce.hpp"

template <typename TaskType>
void runTask() {
    TestRunner<TaskType> runner("./1.Tickets");
    runner.runTests();
}

std::vector<void (*)()> algoVariants = {
    runTask<GetLuckySixBruteforceTask>, runTask<GetLuckyRecursionTask>,
    runTask<GetLuckyAnotherWayBruteforceTask>, runTask<GetLuckyBestAlgoTask>};

int main(int argc, char const *argv[]) {
    std::uint32_t var{};
    std::string input{};

    while (true) {
        std::cout << "Please enter implementation variant [1.." << algoVariants.size()
                  << "] or 'q' to quit: ";

        std::cin >> input;
        if (input == "q")
            return EXIT_SUCCESS;

        var = std::atoi(input.c_str()) - 1;

        if (var >= algoVariants.size())
            continue;

        algoVariants[var]();
    }

    return EXIT_SUCCESS;
}
