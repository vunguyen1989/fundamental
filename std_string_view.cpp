#include <string>

std::size_t len(const std::string &s)
{
    return s.size();
}
int main()
{
    len("hello world");
}