#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> hmap;
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(!hmap.count(nums[i])){
                hmap.insert(pair<int,int>(nums[i], i));
            }
            if(hmap.count(target-nums[i])){
                int n = hmap[target-nums[i]];
                if(n < i){
                    result.push_back(n);
                    result.push_back(i);
                    return result;
                }
            }
        }
        return result;
    }
};

int main(){
    
}