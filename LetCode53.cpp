#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int local = nums[0];
        int global = nums[0];

        for(int i = 1; i < nums.size(); ++i){
            local = max(nums[i], local + nums[i]);
            global = max(local, global);
        }

        return global;
    }
};


int main()
{
    int N;
    cin >> N;
    vector<int> nums;
    int a;
    for(int i = 0; i < N; ++i)
    {
        cin >> a;
        nums.push_back(a);
    }

    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
}
