#include <iostream>
#include <vector>

using namespace std;

int amz(int rows, int columns, vector<vector<int>> grid){
    int ret = 0, cnt = 0, preCnt = 0;
    for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (grid[i][j] == 0)
                    preCnt++;
            }
    }
    
    vector<vector<int>> grid2(grid);
    while (true)
    {
        ret++;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (grid[i][j]==1){
                    //under
                    if (i - 1 >= 0){
                        grid2[i - 1][j] = 1;
                    } 
                    //above
                    if (i + 1 <= rows - 1)
                    {
                        grid2[i + 1][j] = 1;
                    } 
                    //left
                    if (j - 1 >= 0)
                    {
                        grid2[i][j-1] = 1;
                    } 
                    //right
                    if (j + 1 <= columns - 1)
                    {
                        grid2[i][j+1] = 1;
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                if (grid2[i][j] == 0)
                    cnt++;
            }
        }

        if (cnt == preCnt)
            return -1;
        else if (cnt == 0)
            return ret;
        else {
            preCnt = cnt;
            cnt = 0;
            grid.clear();
            grid.assign(grid2.begin(), grid2.end());
        }                
    }
}


int main(){
    // vector<vector<int> > vect{ { 1, 0, 0 }, 
    //                            { 0, 0, 0 }, 
    //                            { 0, 0, 0 } };
    vector<vector<int> > vect{ { 1, 0, 0}, 
                               { 0, 0, 0} };                               
    int ret = amz(2, 3, vect);


    cout << "ret = " << ret <<endl;



    return 0;
}