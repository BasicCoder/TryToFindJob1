#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1;
        int temp = 0;
        if(target < nums[0]) return 0;
        if(target > nums[j]) return j+1;
        //cout << "i: " << i << " j: " << j << endl;
        while(i <= j){
        	temp = (i + j) / 2;
        	
        	if(target == nums[temp])
        		return temp;
        	else if(target < nums[temp]){
        		j = temp - 1;
			}else{
				i = temp + 1;
			}
		//cout << "i: " << i << " j: " << j << endl;
		}
		if(target < nums[i]) return i;
		if(target > nums[i]) return i+1;
		return -1;
    }
};

int main(){
    vector<int> nums;
    int target;
    int N;
    int a;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> a;
        nums.push_back(a);
    }
    cin >> target;

    Solution solution;
    cout << solution.searchInsert(nums, target) << endl;
}
