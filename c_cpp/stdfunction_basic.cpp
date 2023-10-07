#include <iostream>
#include <string>
#include <functional>

std::function <void()> f() {
    std::string h("Hello WOrld");
    return [=] { std::cout << h << std::endl; };
}

int main()
{
    auto func = f();
    func();   // in Hello WOrld
    f()();       // in Hello WOrld
    getchar();
    return 0;
}