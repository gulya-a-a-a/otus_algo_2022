/**
 * The function counts the number of bits set in the transmitted integer.
 * Complexity - O(log(N)).
 *
 * @param  {T} value        : Integral value to find the set bits in it.
 * @return {std::uint32_t}  : Number of set bits in the passed value.
 */
template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
std::uint32_t popcnt_cache(T value)
{
    // The array stores the number of bits set in the corresponding index number.
    static std::uint16_t numToBitsCount[] = {0, 1, 1, 2, 1, 2, 2, 3,
                                             1, 2, 2, 3, 2, 3, 3, 4};
    std::uint32_t result{};

    while (value > 0)
    {
        result += numToBitsCount[value & 0x0f];
        value >>= 4;
    }
    return result;
}