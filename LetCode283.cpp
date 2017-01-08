#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size; ++i){
            if(nums[i] == 0){
                int j = i+1;
                while(j < size && nums[j] == 0)
                    ++j;
                if(j < size){
                    nums[i] = nums[j];
                    nums[j] = 0;             
                }   
            }
        }
    }
};

int main(){
    int a[5] = {0, 1, 0, 3, 12};
    vector<int> nums;
    for(int i = 0; i < 5; ++i){
        nums.push_back(a[i]);
    }
    Solution solution;
    solution.moveZeroes(nums);
    for(int i = 0; i < 5; ++i){
        cout << nums[i] << ' ';
    }
    cout << endl;
}