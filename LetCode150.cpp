#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
private:

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int size = tokens.size();
        if(size == 0) return 0; 

        for(int i = 0; i < size; ++i){
        if(('0' <= tokens[i][0] && tokens[i][0] <= '9') || (tokens[i][0] == '-' && tokens[i].size() >= 2) ){
                int num = atoi(tokens[i].c_str());
                s.push(num);
                //cout << "stack size:" << s.size() << endl;
            }else if(tokens[i][0] == '+'){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int sum = num1 + num2;
                s.push(sum);
            }else if(tokens[i][0] == '-' && tokens[i].size() == 1){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int sum = num2 - num1;
                s.push(sum);
            }else if(tokens[i][0] == '*'){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                int sum = num1 * num2;
                s.push(sum);
            }else if(tokens[i][0] == '/'){
                int num1 = s.top();
                s.pop();
                int num2 = s.top();
                s.pop();
                //cout << "num1:" << num1 << "  num2:" << num2 << endl;
                int sum = num2 / num1;
                s.push(sum);
            }
        }
        return s.top();
    }
};

int main(){
    vector<string> tokens;
    string s;
    cin >> s;
    while(s[0] != '#'){
        tokens.push_back(s);
        cin >> s;
    }
    Solution solution;
    cout << solution.evalRPN(tokens) << endl;

}
