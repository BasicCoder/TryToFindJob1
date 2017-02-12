#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Solution {  
public:  
    int reverse(int x) {  
       
        const int max = 0x7fffffff;  //int最大值  
        const int min = 0x80000000;  //int最小值  
        long long sum = 0;   
          
        while(x != 0)  
        {  
            int temp = x % 10;  
            sum = sum * 10 + temp;  
            if (sum > max || sum < min)   //溢出处理  
            {  
                sum = sum > 0 ? max : min;    
                return 0;  
            }  
            x = x / 10;  
        }  
        return sum;  
    }  
};  
int main(){

}