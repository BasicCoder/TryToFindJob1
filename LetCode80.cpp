#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;

        int k = 0;
        for(int i = 1; i < size; ++i){
            if(k > 1 && nums[k -2] != nums[i] && nums[k -1] == nums[i] && nums[k] == nums[i]){

            }else if( k == 1 && nums[k -1] == nums[i] && nums[k] == nums[i]){

            }else{
                nums[++k] = nums[i];
            }
        }
        return k+1;
    }
};

int main(){
    
}
