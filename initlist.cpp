#include <unordered_map>

void foo(const std::unordered_map<int, int> &) {}

int main()
{
    foo({});
}