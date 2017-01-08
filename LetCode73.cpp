#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector< vector<int> >& matrix) {
        if(matrix.empty() || matrix[0].empty()) return;

        int row = matrix.size();
        int column = matrix[0].size();

        bool rowZero = false;
        bool columnZero = false;
        for(int i = 0; i < row; ++i){
            if(matrix[i][0] == 0) rowZero = true;
        }
        for(int j = 0; j < column; ++j){
            if(matrix[0][j] == 0) columnZero = true;
        }

        for(int i = 1; i < row; ++i){
            for(int j = 1; j < column; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for(int i = 1; i < row; ++i){
            for(int j = 1; j < column; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        if(rowZero){
            for(int i = 0; i < row; ++i)
                matrix[i][0] = 0;
        }
        if(columnZero){
            for(int j = 0; j < column; ++j)
                matrix[0][j] = 0;
        }
    }
};

int main(){
    
}
