#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.empty()) return false;

        int size = s.size();
        vector<bool> flag(size +1, false);
        flag[0] = true;
        for(int i = 1; i <= size; ++i){
            for(int j = i -1; j >= 0; --j){
                if(flag[j]){
                    string word = s.substr(j, i -j);
                    vector<string>::iterator it = find(wordDict.begin(), wordDict.end(), word);
                    if(it != wordDict.end()){
                        flag[i] = true;
                        break;
                    }
                }
            }
        }
        return flag[size];
    }
};

int main(){

}