#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector< vector<int> >& matrix) {
        vector<int> result;
        int row = matrix.size();
    
        if(row == 0 ) return result;

        int col = matrix[0].size();

        int cnt = (min(row, col) + 1) /2;

        for(int i = 0; i < cnt; ++i){
            int lastRow = row -i -1;
            int lastCol = col -i -1;

            if(i == lastRow){
                for(int j = i; j <= lastCol; ++j){
                    result.push_back(matrix[i][j]);
                }
            }else if(i == lastCol){
                for(int j = i; j <= lastRow; ++j){
                    result.push_back(matrix[j][i]);
                }
            }else{
                for(int j = i; j < lastCol; j++){
                    result.push_back(matrix[i][j]);
                }
                for(int j = i; j < lastRow; j++){
                    result.push_back(matrix[j][lastCol]);
                }
                for(int j = lastCol; j > i; j--){
                    result.push_back(matrix[lastRow][j]);
                }
                for(int j = lastRow; j > i; j--){
                    result.push_back(matrix[j][i]);
                }
            }

        }
        return result;

    }
};

int main(){

}
