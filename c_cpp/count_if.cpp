#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
struct IsOdd
{
    bool operator()(int x)
    {
        return x % 2;
    }
};

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7};
    auto x = std::count_if(v.begin(), v.end(), IsOdd());
    std::cout << x << std::endl;

    auto y = std::count_if(v.begin(), v.end(), [](int element) {
        return !(element % 2);
    });
    std::cout << y << std::endl;
}