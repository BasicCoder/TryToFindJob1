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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int size = nums.size();
        if(size == 0) return result;

        int i = 0;
        int j = size -1;
        int index = -1;
        while(i <= j){
            int mid = (i + j) / 2;
            if(target == nums[mid]){
                index = mid;
                break;
            }
            if(target > nums[mid]){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }

        if(index == -1){
            return result;
        }else{
            i = index;
            j = index;
            while(nums[i] == target && i >= 0) --i;
            while(nums[j] == target && j <= size -1) ++j;
            result[0] = ++i;
            result[1] = --j;
            return result;
        }
        return result;
    }
};

int main(){

}
