#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdlib>
#include <string>
#include <map>

using namespace std;


// 这个问题是参考网上解题方法，还没搞懂
class Solution {
private:
    bool isValid(string t){
        int cnt = 0; 
        for(int i = 0; i < t.size(); ++i){
            if(t[i] == '(') ++ cnt;
            if(t[i] == ')' && cnt -- ==0) return false;
        }
        return cnt == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        map<string, int> visited;
        queue<string> q;
        q.push(s);
        ++visited[s];
        bool found = false;
        while(!q.empty()){
            s = q.front();
            q.pop();
            if(isValid(s)){
                res.push_back(s);
                found = true;
            }
            
            if(found) continue;

            for(int i = 0; i < s.size(); ++i){
                if(s[i] != '(' && s[i] != ')') continue;
                string t = s.substr(0, i) + s.substr(i+1);
                if(visited.find(t) == visited.end()){
                    q.push(t);
                    ++visited[t];
                }
            }
        }
        return res;
    }
};

int main(){
    
}
