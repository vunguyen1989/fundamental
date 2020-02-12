// split the ON LEDs into Hours and Minutes
// Find the possible ON LEDs for Hours->Put them in a vector
// Repeat for Minutes

// Every Hour combination can map to a Minute combination
// But there may be some invalid combinations like 12:00;
// Discard them
#include <vector>
using namespace std;

void foo(vector<vector<int>>& m,vector<int>& cur,vector<int>& elms,int start,int r)
{
    if (r==0)
    {
        m.push_back(cur);
        return;
    }
    else
    {
        for (int i=start;i<=elms.size()-r;++i)
        {
            cur.push_back(elms[i]);
            foo(m,cur,elms,i+1,r-1);
            cur.pop_back();
        }
    }
}

vector<vector<int>> helper(vector<int>& elms,int r)
{
    vector<vector<int>> m;
    vector<int> cur;

    if (r>elms.size()) return m;

    foo(m,cur,elms,0,r);

    return m;
}

string convert(vector<int>& h,vector<int>& m)
{
    int H = accumulate(h.begin(),h.end(),0);
    //if (H==12) H=0; 
    int M = accumulate(m.begin(),m.end(),0);
    //if (M==60) M=0; 
    
    if (H>=12 || M>=60) return "@";
    
    stringstream a;
    a<<H;
    stringstream b;
    b<<M;
    
    string A = a.str();
    string B = b.str();
    
    //if (A.size()==1) A = "0"+A;
    if (B.size()==1) B = "0"+B;
    
    return A+":"+B;
}

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        
        vector<string> ans;
        vector<int> hour = {8,4,2,1};
        vector<int> minute = {32,16,8,4,2,1};
        
        for (int H=0;H<=num;++H)
        {
            int M = num-H;
            
            vector<vector<int>> hr = helper(hour,H);
            vector<vector<int>> m = helper(minute,M);
            
            for (int i=0;i<hr.size();++i)
            {
                for (int j=0;j<m.size();++j)
                {
                    string p = convert(hr[i],m[j]);
                    
                    if (p!="@") ans.push_back(p);
                }
            }
            
        }
       
        //sort(ans.begin(),ans.end());
        return ans;
    }
};