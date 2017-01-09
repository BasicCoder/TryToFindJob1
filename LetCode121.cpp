#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size < 2) return 0;

        int maxPro = 0;
        int curMin = prices[0];

        for(int i = 1; i < size; ++i){
            curMin = min(curMin, prices[i]);
            maxPro = max(maxPro, prices[i] - curMin);
        }
        return maxPro;

    }
};

int main(){

}
