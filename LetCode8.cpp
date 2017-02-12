#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        const int MAX = 0x7fffffff;
        const int MIN = 0x80000000;
        long long  sum = 0;
        int signal = 1;

        int len = str.length();
        if(len == 0 ) return 0;

        int i = 0;
        while(str[i] != '\0' && str[i] == ' ') ++i;
        
	
        if(str[i] == '\0') return 0;
        
        if(str[i] == '+'){
            signal = 1;
            ++i;
        }else if(str[i] == '-'){
            signal = -1;
            ++i;
        }
        
	
        while(str[i] != '\0'){
            if(str[i] >= '0' && str[i] <= '9'){
                sum = sum * 10 + signal * (str[i] - '0');
            }else{
                return sum;
            }

            if(sum > MAX || sum < MIN){
                sum = sum > 0 ? MAX : MIN;
                return sum;
            }
            ++i;
        }
        return sum;

    }
};

int main(){
    string s;
    Solution solution;
    cin >> s;
    cout << solution.myAtoi(s) << endl;
}
