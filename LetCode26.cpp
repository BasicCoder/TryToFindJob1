#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)return 0;
        int k = 0;
        for(int i = 1; i < size; ++i){
            if(nums[k] != nums[i]){
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};

int main(){
    
}