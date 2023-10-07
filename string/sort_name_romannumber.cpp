#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, int> uM = {{"I", 1}, {"II", 2}, {"III", 3}, {"IV", 4}, {"V", 5}, {"VI", 6}, {"VII", 7}, {"VIII", 8}, {"IX", 9}, {"X", 10}, {"XI", 11}, {"XII", 12}, {"XIII", 13}, {"XIV", 14}, {"XV", 15}, {"XVI", 16}, {"XVII", 17}, {"XVIII", 18}, {"XIX", 19}, {"XX", 20}, {"XXI", 21}, {"XXII", 22}, {"XXIII", 23}, {"XXIV", 24}, {"XXV", 25}, {"XXVI", 26}, {"XXVII", 27}, {"XXVIII", 28}, {"XXIX", 29}, {"XXX", 30}, {"XXXI", 31}, {"XXXII", 32}, {"XXXIII", 33}, {"XXXIV", 34}, {"XXXV", 35}, {"XXXVI", 36}, {"XXXVII", 37}, {"XXXVIII", 38}, {"XXXIX", 39}, {"XL", 40}, {"XLI", 41}, {"XLII", 42}, {"XLIII", 43}, {"XLIV", 44}, {"XLV", 45}, {"XLVI", 46}, {"XLVII", 47}, {"XLVIII", 48}, {"XLIX", 49}, {"L", 50}};
std::vector<std::string> SortNameAndRoman(std::vector<std::string> &names)
{
    std::vector<std::string> ret;
    std::map<std::string, std::string> m;
    for (auto s : names)
    {
        auto first_token = s.substr(0, s.find(' '));
        auto last_token = s.substr(s.find(" ") + 1, s.size() - s.find(" "));
        auto it = uM.find(last_token);
        auto m_key = first_token + "0";
        m_key.back() = '0' + it->second;
        m[m_key] = s;
    }
    for (auto it = m.begin(); it != m.end(); it++)
    {
        ret.push_back(it->second);
    }
    return ret;
}

int main()
{
    std::vector<std::string> inputs;
    inputs.push_back("Phillip XI");
    inputs.push_back("Abcd IX");
    inputs.push_back("Abcdx VI");
    inputs.push_back("A VI");
    inputs.push_back("Louis XVI");
    inputs.push_back("Louis XV");

    for (auto i : inputs)
    {
        std::cout << i << std::endl;
    }

    std::cout << "----------------\n";

    auto names = SortNameAndRoman(inputs);
    std::cout << "----------------\n";
    for (auto i : names)
    {
        std::cout << i << std::endl;
    }
}
