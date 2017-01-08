#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        vector< vector<string> > result;

        int size = strs.size();
        if(size == 0) return result;

        map<string, vector<string> > hashMap;

        for(int i = 0; i < size; i++){
            string s = strs[i];
            string t = s;
            sort(t.begin(), t.end());

            if(hashMap.find(t) == hashMap.end()){
                vector<string> group;
                group.push_back(s);
                hashMap.insert(pair<string, vector<string> >(t, group));
            }else{
                hashMap[t].push_back(s);
            }
        }
        for(map<string, vector<string> >::iterator it = hashMap.begin(); it != hashMap.end(); ++it){
            vector<string> group(it -> second);
            sort(group.begin(), group.end());
            result.push_back(group);
        }

        return result;
    }
};

int main(){
    
}
