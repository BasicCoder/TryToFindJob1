#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        if(size < 2) return 0;
        int max = 0;
        int l = 0;
        int r = size -1;
        while(l < r){
            int cur = (r - l) * min(height[l], height[r]);
            if(cur > max) max = cur;
            if(height[l] < height[r]) l++;
            else r--;
        }
        return max;
    }
};

int main(){
    
}