#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int total = 0;
        while(n){
            ++total;
            n = n & (n - 1);
        }
        return total;
    }
};

int main(){
    uint32_t n;
    cin >> n;
    Solution solution;
    cout << solution.hammingWeight(n) << endl;
}
