#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        for(int reach = 0; i < size && i <= reach; ++i){
            reach = max(i + nums[i], reach);
        }
        return i == size;
    }
};

int main(){
    
}
