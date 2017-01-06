#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

//根据提示是这么做的
class Solution {
public:
    int addDigits(int num) {
        return (num -1) % 9 + 1;
    }
};

//传统解法，不可避免要循环
class Solution1{
public:
    int addDigits(int num){
        while(num / 10 > 0){
            int sum = 0;
            while(num > 0){
                sum += num %10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main(){
    
}