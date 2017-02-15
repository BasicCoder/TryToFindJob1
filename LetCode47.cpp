#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    void recursive(vector<int> num, int i, int j, vector< vector<int> >& res){
        if(i == j -1){
            res.push_back(num);
            return ;
        }
        for(int k = i; k < j; ++k){
            if(i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursive(num, i+1, j, res);
            swap(num[i], num[k]);
        }
    }
public:
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector< vector<int> > res;
        recursive(nums, 0, nums.size(), res);
        return res;
    }
};

int main(){

}
