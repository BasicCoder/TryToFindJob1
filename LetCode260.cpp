#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> result(2, 0);
        int res = nums[0];
        int size = nums.size();
        for(int i = 1; i < size; ++i){
            res ^= nums[i];
        }

        int n = res & (~ (res - 1));
        for(int i = 0; i < size; ++i){
            if((n & nums[i]) != 0 ){
                result[0] = result[0] ^ nums[i];
            }
            else{
                result[1] = result[1] ^ nums[i];
            }
        }

        return result;
    }
};

int main(){
    
}
