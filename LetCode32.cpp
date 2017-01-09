#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
private:
    struct Parenthese{
        int i;
        char c;
        Parenthese(int _i, char _c):i(_i), c(_c){}
    };
public:
    int longestValidParentheses(string s) {
        stack<Parenthese> stk;
        int length = s.length();
        if(length == 0) return 0;

        int max = 0;
        for(int i = 0; i < length; ++i){
            if(s[i] == '('){
                Parenthese parenthese(i, s[i]);
                stk.push(parenthese);
            }else{
                if(!stk.empty() && stk.top().c == '('){
                    int curlen = 0;
                    stk.pop();
                    if(stk.empty()){
                        curlen = i +1; 
                    }else{
                        curlen = i - stk.top().i;
                    }
                    if(curlen > max) max = curlen;
                }else{
                    Parenthese parenthese(i,s[i]);
                    stk.push(parenthese);
                }
            }
        }

        return max;
    }
};

int main(){
	string s;
    cin >> s;
    Solution solution;
    
    while(s != "#"){
        cout << solution.longestValidParentheses(s) << endl;
        cin >> s;
    }
}
