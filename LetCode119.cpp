#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for(int i = 1; i < rowIndex + 1; ++i){
            for(int j = i; j >= 1; --j){
                A[j] += A[j -1];
            }
        }
        return res;
    }
};

int main(){
    
}