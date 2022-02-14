#include <iostream>

class Paint final {

    const char *terminalControlSequence = "\033[";

    const char *m_colours[7] = {
        "34", // blue
        "34", // blue
        "33", // orange
        "33", // orange
        "33", // orange
        "33", // orange
        "32"  // green
    };

    const char *m_symbols = " #<>^VX";

    int **m_map;
    unsigned int m_w, m_h;

  public:
    Paint(unsigned int w, unsigned int h) : m_w{w}, m_h{h} {
        m_map = new int *[m_w] {};
        for (size_t i = 0; i < m_w; i++) {
            m_map[i] = new int[m_h];
        }
    }

    ~Paint() {
        for (size_t i = 0; i < m_w; i++) {
            delete[] m_map[i];
        }
        delete[] m_map;
    }

    void AddRandomPixels(int count) {
        std::srand(time(NULL));
        for (size_t i = 0; i < count; i++) {
            SetMap(std::rand() % m_w, (std::rand() % m_h), 1);
        }
        SetCursor(m_w, m_h);
    }

    void FillRecursion(int x, int y, int value) {
        if (!IsEmpty(x, y)) {
            return;
        }
        SetMap(x, y, value);
        std::getchar();
        FillRecursion(x, y + 1, 5);
        FillRecursion(x, y - 1, 4);
        FillRecursion(x + 1, y, 3);
        FillRecursion(x - 1, y, 2);
        SetMap(x, y, 6);
    }

    bool IsEmpty(int x, int y) {
        if ((x >= m_w) || (x < 0)) {
            return false;
        }

        if ((y >= m_h) || (y < 0)) {
            return false;
        }

        return m_map[x][y] == 0;
    }

    void SetMap(int x, int y, int value) {
        m_map[x][y] = value;
        SetColor(m_colours[value]);
        SetCursor(x, y) << m_symbols[value];
    }

    std::ostream &SetColor(const char *colorNumber) {
        return std::cout << terminalControlSequence << colorNumber << "m";
    }

    std::ostream &SetCursor(int x, int y) {
        return std::cout << terminalControlSequence << y + 2 << ";" << x << "H";
    }
};

int main(int argc, char const *argv[]) {
    Paint paint(50, 20);

    paint.AddRandomPixels(400);

    paint.FillRecursion(25, 10, 1);

    return 0;
}
