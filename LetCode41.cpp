#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)return 1;

        for(int i = 0; i < size; ++i){
            while(nums[i] > 0 && nums[i] <= size && nums[nums[i] -1] != nums[i]){
                int tmp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = tmp;
            }
        }
        for(int i = 0; i < size; ++i){
            if(nums[i] != i +1){
                return i+1;
            }
        }
        return size +1;
    }
};

int main(){
    
}