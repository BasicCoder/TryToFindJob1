#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        if(length == 0) return 0;

        int len = 0;
        for(int i = length -1; i >= 0; --i){
            while(s[i] == ' ' && i >= 0) --i;

            while(s[i] != ' ' && i >= 0){
                ++len;
                --i;
            }
            if(s[i] == ' ') return len;
        }

        return len;
    }
};

int main(){
    string s;
    s = "Hello World";
    Solution solution;
    
    while(s != "#"){   	
        cout << solution.lengthOfLastWord(s) << endl;
        
        cin >> s;
    }
}
