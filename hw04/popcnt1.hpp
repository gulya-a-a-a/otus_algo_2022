template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
std::uint32_t popcnt1(T value)
{
    std::uint32_t result{};

    while (value > 0)
    {
        if ((value & 1UL) == 1)
            result++;

        value >>= 1;
    }
    return result;
}