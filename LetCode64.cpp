#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector< vector<int> >& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector< vector<int> > sum(row, vector<int>(col, grid[0][0]));

        for(int i = 1; i < row; ++i)
            sum[i][0] = sum[i -1][0] + grid[i][0];
        for(int j = 1; j < col; ++j)
            sum[0][j] = sum[0][j-1] + grid[0][j];
        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                sum[i][j] = min(sum[i -1][j], sum[i][j -1]) + grid[i][j];
            }
        }
        return sum[row -1][col -1];
    }
};

int main(){

}