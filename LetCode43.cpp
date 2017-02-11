#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();

        vector<int> tmpres(len1 + len2, 0);
        int k = len1 + len2 - 2;
        for(int i = 0; i < len1; ++i){
            for(int j = 0; j < len2; ++j){
                tmpres[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
            }
        }

        int flag = 0;

        for(int i = 0; i < len1 + len2; i++){
            tmpres[i] += flag;
            flag = tmpres[i]/10;
            tmpres[i] %= 10;
        }
        int i = k+1;
        while(tmpres[i] == 0) i--;
        
        if(i < 0) return "0";
        string res;
        for(; i >= 0; --i)
            res.push_back(tmpres[i] + '0');
        return res;
    }
};

int main(){
    
}
