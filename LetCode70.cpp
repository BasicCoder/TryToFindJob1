#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
private:
    int  array[51];  //根据研究，斐波那契数列在前50位左右已经很大，超出int值表示范围，利用数组提前算好，                    
                     //可以避免递归运算空间复杂度，一次计算即可。
    
public:
    Solution(){
        array[0] = 0;
        array[1] = 1;
        array[2] = 2;
        for(int i = 3; i < 51; ++i){
            array[i] = array[i-1] + array[i-2];
        }
    }
public:
    int climbStairs(int n) {       
        return array[n];
    }
};


int main(){
    int N;
    cin >> N;
    Solution solution;
    cout << solution.climbStairs(N) << endl;
}
