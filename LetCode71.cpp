#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstdlib>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        int length = path.length();

        string result;
        if(length == 0) return result;

        stack<string> ss;
        for(int i = 0; i < length; ++i){
            while(i < length && path[i] == '/')
                ++i;
            
            string s = "";
            while(i < length && path[i] != '/')
                s += path[i++];
            if(s == ".." && !ss.empty())
                ss.pop();
            else if(s != "" && s != "." && s != "..")
                ss. push(s);
        }

        if(ss.empty())
            return "/";
        string s = "";
        while(!ss.empty()){
            s = "/" + ss.top() + s ;
            ss.pop();
        }
        return s;
    }
};

int main(){

}
