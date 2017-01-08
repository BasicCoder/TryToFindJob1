#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

// 时间超出
class Solution1 {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        int srclen = s.length();
        int modlen = p.length();

        if(srclen == 0 || modlen == 0 || modlen > srclen) return result;

        string b = p;
        sort(b.begin(), b.end());

        for(int i = 0; i <= srclen - modlen; ++i){
            string str = s.substr(i, modlen);
            sort(str.begin(), str.end());

            if(str == b){
                result.push_back(i);
            }
        }

        return result;
    }
};

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        
        int srclen = s.length();
        int modlen = p.length();

        if(srclen == 0 || modlen == 0 || modlen > srclen) return result;

       vector<int> h1(26), h2(26);
       for(int i = 0; i < modlen; ++i){
           ++h1[p[i] - 'a']; 
       }

       for(int i = 0; i < srclen; ++i){
           ++h2[s[i] - 'a'];
           if(i >= modlen)
                --h2[s[i-modlen] - 'a'];
           if(h1 == h2)
                result.push_back(i-modlen+1);
       }

        return result;
    }
};

int main(){
	string s, p;
    cin >> s >> p;
    Solution solution;
    solution.findAnagrams(s, p);
}
