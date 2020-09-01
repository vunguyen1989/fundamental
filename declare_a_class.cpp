#include <iostream>
#include <type_traits>

class YMD
{
    int mY;

public:
    YMD() = default;
};

int main()
{
    static_assert(std::is_trivially_destructible<YMD>{});
    return 0;
}