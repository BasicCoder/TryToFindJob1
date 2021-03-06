#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> >res;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int target = -nums[i];
            int front = i + 1;
            int back = nums.size() - 1;

            while(front < back){
                int sum = nums[front] + nums[back];

                if(sum < target){
                    ++front;
                }else if (sum > target){
                    --back;
                }else{
                    vector<int> elem(3, 0);
                    elem[0] = nums[i];
                    elem[1] = nums[front];
                    elem[2] = nums[back];
                    res.push_back(elem);

                    while(front < back && nums[front] == elem[1]) ++front;
                    while(front < back && nums[back] == elem[2]) --back;
                }
            }

            while(i + 1 < nums.size() && nums[i+1] == nums[i]) ++i;
        }

        return res;
    }
};

int main(){

}
