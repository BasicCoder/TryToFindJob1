#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;


//编译器对栈溢出处理不一样，本地未判断sc.empty()，未出现run error，OJ上会出现error.
class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        if(length == 0) return true;

        stack<char> sc;
        for(int i = 0; i < length; ++i){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sc.push(s[i]);
            }else if(s[i] == ')' && !sc.empty() && sc.top() == '('){
                sc.pop();
            }else if(s[i] == ']' && !sc.empty() && sc.top() == '['){
                sc.pop();
            }else if(s[i] == '}' && !sc.empty() && sc.top() == '{'){
                sc.pop();
            }else{
                return false;
            }
        }
        if(sc.empty()){
            return true;
        }   
        else
            return false;
    }
};

int main(){
    string s;
    cin >> s;
    Solution solution;
    
    while(s != "#"){
        cout << solution.isValid(s) << endl;
        cin >> s;
    }
    
}
