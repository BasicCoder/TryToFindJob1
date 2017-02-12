#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > fourSum(vector<int>& nums, int target) {
        vector< vector<int> > res;

        if(nums.empty())return res;

        sort(nums.begin(), nums.end());

        int size = nums.size();
        for(int i = 0; i < size; ++i){
            int target3 = target - nums[i];
            for(int j = i + 1; j < size; ++j){
                int target2 = target3 - nums[j];

                int front = j +1;
                int back = size - 1;

                while(front < back){
                    int sum = nums[front] + nums[back];
                    if(sum < target2) ++front;
                    else if (sum > target2) --back;
                    else{
                        vector<int> elem(4, 0);
                        elem[0] = nums[i];
                        elem[1] = nums[j];
                        elem[2] = nums[front];
                        elem[3] = nums[back];
                        res.push_back(elem);

                        while(front < back && nums[front] == elem[2]) ++front;
                        while(front < back && nums[back] == elem[3]) -- back;
                  
                      }
                }
                while(j +1 < size && nums[j+1] ==nums[j]) ++j;
            }
            while(i +1 < size && nums[i+1] == nums[i]) ++i;
        }

        return res;
    }
};


int main(){
    
}
