#include <iostream>
#include <stack>
#include <string>
#include <vector>

std::string AddBrace(std::string str)
{
    std::stack<char> s;
    int close = 0;
    for (auto i : str)
    {
        if (i == '<')
        {
            s.push(i);
            continue;
        }
        if (i == '>' && s.size() != 0)
        {
            s.pop();
            continue;
        }
        if (i == '>')
        {
            close++;
        }
    }
    return std::string(close, '<') + str + std::string(s.size(), '>');
}
int main()
{
    std::vector<std::string> v = {
        "<",
        ">",
        ">>",
        "<<><>>>",
        "<<>>><"};
    for (auto i : v)
    {
        auto ret = AddBrace(i);
        std::cout << i << " \t\t\t\t=> output : " << ret << std::endl;
    }
}