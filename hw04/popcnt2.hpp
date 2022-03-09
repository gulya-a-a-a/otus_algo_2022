/**
 * The function counts the number of bits set in the transmitted integer.
 * Complexity - O(log(N)).
 *
 * @param  {T} value        : Integral value to find the set bits in it.
 * @return {std::uint32_t}  : Number of set bits in the passed value.
 */
template <typename T, std::enable_if_t<std::is_integral_v<T>, bool> = true>
std::uint32_t popcnt2(T value)
{
    std::uint32_t result{};

    while (value > 0)
    {
        result++;
        value &= value - 1;
    }
    return result;
}