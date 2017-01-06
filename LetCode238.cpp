#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        vector<int> result1(size, 1);
        vector<int> result2(size ,1);
        int pre = 1;
        int post = 1;
        for(int i = 1; i < size; ++i){
            result1[i] = nums[i-1] * result1[i-1];
        }
        for(int i = size -2; i >= 0; --i){
            result2[i] *= nums[i+1] * result2[i+1];
        }
        for(int i = 0; i < size; ++i){
            result[i] = result1[i] * result2[i];
        }

        return result;

    }
};

int main(){
    
}