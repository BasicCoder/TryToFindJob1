#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    void dfs(int index, string& s, vector<string>& path, vector< vector<string> >& res){
        if(index == s.size()){
            res.push_back(path);
            return;
        }

        for(int i = index; i < s.size(); ++i){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index +1));
                dfs(i+1, s, path, res);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int index, int i){
        while(index <= i){
            if(s[index++] != s[i--])
                return false;
        }
        return true;
    }
public:
    vector< vector<string> > partition(string s) {
        vector< vector<string> > res;

        if(s.empty()) return res;

        vector<string> path;
        dfs(0, s, path, res);

        return res;
    }
};

int main(){

}