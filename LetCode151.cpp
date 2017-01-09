#include <iostream>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int length = s.length();
        if(length == 0) return;

        stack<string> stk;

        for(int i = 0; i < length; ++i){
            while(s[i] == ' ' && i < length)++i;
            string str;
            while(s[i] != ' ' && i < length){
                str += s[i];
                ++i;
            }
            if(str != "") stk.push(str);
        }
        s.clear();
        while(!stk.empty()){
            s += stk.top();
            stk.pop();
            if(stk.size() >=1){
                s += ' ';
            }
        }

    }
};

int main(){
    string s;
    s = "the sky is blue";
    Solution solution;
    
    while(s != "#"){   	
        solution.reverseWords(s);
        cout << s << endl;
        cin >> s;
    }
}
