#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int length = s.length();
        for(int i = 0; i < length; ++i){
            result *= 26;
            result += (s[i] - 'A' + 1);
        }

        return result;
    }
};

int main(){
    string s;
    Solution solution;
    while(cin >> s){
        cout << solution.titleToNumber(s) << endl;
    }
}
