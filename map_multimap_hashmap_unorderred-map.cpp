/*
    [x] which container allow same keys => multimap
    [x] find in multimap => equal_range
    [x] When they have same keys, how they update the values => equal_range -> set key, value
    [x] when having same keys, how to erase 
    [] hash-map
*/
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

void MultiMap()
{
    std::multimap<std::string, int> m;
    m.insert({"a", 6});
    m.insert({"a", 6});
    m.insert({"1", 6});
    for (auto i : m)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }

    // m["a"] = 9; //error

    std::cout << "------\n";
    auto it = m.equal_range("a");
    for (auto itr = it.first; itr != it.second; ++itr)
    {
        if (itr->second == 6)
            itr->second = 7;
    }
    for (auto i : m)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }

    std::cout << "------\n";
    m.erase("a");
    for (auto i : m)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }
}

void Map()
{
    std::map<std::string, int> m;
    m.insert({"a", 5});
    m.insert({"1", 6});
    for (auto i : m)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }
    m["a"] = 9;
    std::cout << "-----------\n";
    for (auto i : m)
    {
        std::cout << i.first << " - " << i.second << std::endl;
    }
}

int main()
{
    MultiMap();
}