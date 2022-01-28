#include <cmath>
#include <iostream>
#include <vector>

using DrawingConditionPredicate = bool (*)(int, int, int);

void drawSquare(DrawingConditionPredicate predicate) {
    const int squareSide = 25;
    for (int y = 0; y < squareSide; ++y) {
        for (int x = 0; x < squareSide; ++x) {
            std::cout << (predicate(x, y, squareSide) ? "# " : ". ");
        }
        std::cout << '\n';
    }
}

std::vector<DrawingConditionPredicate> predicates = {
    // 01
    [](int x, int y, int) { return x > y; },

    // 02
    [](int x, int y, int) { return (x == y); },

    // 03
    [](int x, int y, int squareSize) { return (x == squareSize - 1 - y); },

    // 04
    [](int x, int y, int squareSize) {
        return (y < squareSize - x + (squareSize / 5));
    },

    // 05
    [](int x, int y, int squareSize) {
        return (y == static_cast<uint32_t>(x / 2));
    },

    // 06
    [](int x, int y, int squareSize) {
        return y < squareSize * 0.4 || x < squareSize * 0.4;
    },
    // 07
    [](int x, int y, int squareSize) {
        return y > squareSize * 0.6 && x > squareSize * 0.6;
    },

    // 08
    [](int x, int y, int squareSize) { return x * y == 0; },

    // 09
    [](int x, int y, int squareSize) {
        auto shift = squareSize / 2 - 2;
        return (y > x + shift) || (y + shift < x);
    },

    // 11
    [](int x, int y, int squareSize) {
        return y == 1 || x == 1 || y == (squareSize - 2) ||
               x == (squareSize - 2);
    },

    // 12
    [](int x, int y, int squareSize) {
        uint32_t radiusSquared = pow(20, 2);
        return (pow(y, 2) + pow(x, 2)) < radiusSquared;
    },

    // 14
    [](int x, int y, int squareSize) {
        uint32_t radiusSquared = pow(21, 2);
        return (pow(y - squareSize, 2) + pow(x - squareSize, 2)) > radiusSquared;
    }};

int main(int argc, char const *argv[]) {
    size_t spellNumber{};
    std::string input{};

    while (true) {
        std::cout << "Please enter the number of the next spell to show "
                     "[1.."
                  << predicates.size() << "] or 'q' to quit: ";

        std::cin >> input;
        if (input == "q")
            break;

        spellNumber = std::atoi(input.c_str());
        if (spellNumber < 1 || spellNumber > predicates.size())
            continue;

        drawSquare(predicates[spellNumber - 1]);
    }

    return 0;
}
