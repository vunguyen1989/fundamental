#include <stdio.h>
#include <string>

bool is_balanced(std::string expression) {
//   stack<char> s;
  for (char c : expression) {
    // if      (c == '{') s.push('}');
    // else if (c == '[') s.push(']');
    // else if (c == '(') s.push(')');
    // else {
    //   if (s.empty() || c != s.top())
    //     return false;
    //   s.pop();
    // }
  }
//   return s.empty();
    return true;
}
int main(){
    printf ("Hello world!\n");
    return 0;
}