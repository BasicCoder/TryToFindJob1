#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return;

        int i = len - 2;
        while(i >=0 && nums[i] >= nums[i+1]) --i;

        if(i >= 0){
            int j = i + 1;

            while(j < len && nums[j] > nums[i]) ++j;
            --j;

            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }

        reverse(nums.begin() + i +1, nums.end());
    }
};

int main(){
    
}
