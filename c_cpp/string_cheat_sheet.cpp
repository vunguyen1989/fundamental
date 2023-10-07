#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <iterator>
#include <sstream>
#include <string>
#include <vector>

template <typename Out>
void split(const std::string &s, char delim, Out result)
{
  std::istringstream iss(s);
  std::string item;
  while (std::getline(iss, item, delim))
  {
    *result++ = item;
  }
}

std::vector<std::string> SplitString(const std::string &s, char delim)
{
  std::vector<std::string> elems;
  split(s, delim, std::back_inserter(elems));
  return elems;
}

void CreateNewString()
{
  std::string greeting = "Hello";
  std::string new_greeting;
  for (int n = greeting.length() - 1; n >= 0; n--)
  {
    new_greeting.push_back(greeting[n]);
  }
  std::cout << "Original string: " << greeting << std::endl;
  std::cout << "New reversed string: " << new_greeting << std::endl;
}
std::string RestoreString()
{
  //  complexcity O(n)
  std::string s = "codeleet";
  std::vector<int> indices{4, 5, 6, 7, 0, 2, 1, 3};
  if (s.size() != indices.size())
  {
    return "";
  }
  std::map<int, char> m;
  for (auto i = 0; i < indices.size(); i++)
  {
    m[indices[i]] = s[i];
  }
  std::string ret = "";
  for (auto it = m.begin(); it != m.end(); it++)
  {
    ret.push_back((*it).second);
  }
  std::cout << ret << std::endl;
  return ret;
}
void RemoveLastChar()
{
  //remove last charactor
  std::string myString("gatronggaylete");
  auto st = myString.substr(0, myString.size() - 1);
  std::cout << st << std::endl;

  // from C++11
  st.pop_back();
  std::cout << st << std::endl;
}
void ReVerseString()
{
  std::string st("gatronggaylete");
  std::reverse(st.begin(), st.end());
  std::cout << st << std::endl;
}

void SubString()
{
  std::string s = "one two";
  auto first_token = s.substr(0, s.find(' '));
  std::cout << first_token << std::endl; //one
  auto last_token = s.substr(s.find(' ') + 1, s.size() - s.find(" "));
  std::cout << last_token << std::endl; //two
}
int main()
{
  // CreateNewString();
  // RemoveLastChar();
  // ReVerseString();
  // RestoreString();
  // SubString();

  {
    auto vs = SplitString("ga trong gay 123", ' ');
    for (auto i : vs)
    {
      std::cout << i << std::endl;
    }
  }
}