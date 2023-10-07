#include <iostream>

With C++11 you can use std::regex like so:

    #include <regex>
    ...
    std::string string("hello $name");
    string = std::regex_replace(string, std::regex("\\$name"), "Somename");
The double backslash is required for escaping an escape character.