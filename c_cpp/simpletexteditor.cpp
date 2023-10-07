#include <cmath>
#include <cstdio>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<char> v;
    int Q;
    cin >> Q;
    pair<int, string> lastStep;
    for (int i = 0; i < Q; i++){
        int t;
        string arg;
        cin >> t;
        switch (t) {
            case 1://add
                {
                    cin >> arg;
                    lastStep.first = 1;
                    lastStep.second = arg;
                    insert_iterator<vector<char>> insIt(v, v.end());
                    copy(arg.begin(), arg.end(), insIt);
                    break;
                }
            case 2://delete last k elements
                {
                    int k;
                    cin >> k;
                    lastStep.first = 2;
                    lastStep.second = string(v.end()-k, v.end());
                    v.erase(v.end() - k, v.end());
                }
            case 3:// print kth char
                {
                    int k;
                    cin >> k;
                    cout << v[k - 1] << endl;
                }
            case 4:
                {
                    if (lastStep.first == 1){
                        v.erase(v.end() - lastStep.second.size(), v.end());
                    } else if (lastStep.first == 2){
                        insert_iterator<vector<char>> insIt(v, v.end());
                        copy(lastStep.second.begin(), lastStep.second.end(), insIt);
                    }
                }
                
            default:
                break;    
        }

    }
    return 0;
}
