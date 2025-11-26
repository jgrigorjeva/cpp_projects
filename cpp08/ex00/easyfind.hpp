#include <algorithm>

template <typename T>
int easyfind(T& haystack, int needle)
{
    return std::find(haystack.begin(), haystack.end(), needle)
}
