#include <boost/algorithm/string.hpp>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    std::string text = "Let me split this into words";
    std::vector<std::string> results;
    
    boost::split(results, text, [](char c){return c == ' ';});

    // for (int i = 0; i < results.size(); i++){
    //     cout << results[i] << endl;
    // }

    //no boost
    std::string s = "split on    whitespace   ";
    std::vector<std::string> result;
    std::istringstream iss(s);
    for(std::string s; iss >> s; )
        result.push_back(s);

    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    } 
}
