#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        if(needle.length() > haystack.length())
            return -1;

        int m = haystack.length();
        int n = needle.length();
        for(int i = 0; i <= m - n; ++i){
            int j = 0;
            for(j = 0; j < needle.length(); ++j){
                if(haystack[i+j] != needle[j])
                    break;
            }
            if(j == n)
                return i;
        }
        return -1;
    }
};

int main(){
	
	
}
