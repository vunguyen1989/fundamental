#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>

void VectorSize(){
    std::vector<int> v(10);
    std::cout << v.size() << std::endl; //returns 10
    std::vector<int> v1;
    v1.reserve(10);
    std::cout << v1.size() << std::endl; //returns 0

}
void VectorToSet(){
    std::vector <int> v{1, 5, 8, 6, 8, 2};
    for (auto i : v){
        std::cout << i <<" ";
    }
    std::cout << std::endl;

    std::unordered_set<int> s(v.begin(), v.end());
    for (auto i : s){
        std::cout << i <<" ";
    }
    std::cout << std::endl;
}
void VectorMax(){
    std::vector <int> v{1, 5, 8, 6, 8, 2};
    auto max2 = *std::max_element (v.begin(), v.end());
    std::cout << max2 << std::endl;
}

int main (){
    // VectorSize();
    // VectorToSet();
    VectorMax();
}

