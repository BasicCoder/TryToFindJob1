#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector< vector<int> >& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        
		if(row <=0 || col <= 0) return 0;
        
        if(obstacleGrid[0][0] || obstacleGrid[row -1][col -1]) return 0;

        vector< vector<int> > sum(row, vector<int>(col, 1));

        for(int i = 1; i < row; ++i){
            if(obstacleGrid[i][0]){
                for(int j = i; j < row; ++j)
                    sum[j][0] = 0;
                break;
            }
        }

        for(int j = 1; j < col; ++j){
            if(obstacleGrid[0][j]){
                for(int i = j; i < col; ++i)
                    sum[0][i] = 0;
                break;
            }
        }        

        for(int i = 1; i < row; ++i){
            for(int j = 1; j < col; ++j){
                if(!obstacleGrid[i][j]){
                    sum[i][j] = sum[i -1][j] + sum[i][j -1];
                }else{
                    sum[i][j] = 0;
                }
            }
        }
        return sum[row -1][col -1];
    }
};

int main(){

}
