#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> int_map;
        for(int i = 0; i < nums.size(); ++i){
            if(int_map.count(nums[i])){
                return true;
            }
            int_map.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};

int main(){

}