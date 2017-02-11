#include <iostream>
#include <string>

using namespace std;

class Solution {
private:
    bool isalpha(char &c){
        if( c >= 'A' && c <= 'Z'){
            c = c - 'A' + 'a';
            return true;
        }
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    }
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n -1;
        while(i < j){
            if( !isalpha(s[i])){
                ++i;
                continue;
            }
            if( !isalpha(s[j])){
                --j;
                continue;
            }
            if(s[i] != s[j]) return false;
            ++i;
            --j;
        }
        return true;
    }
};


int main(){
    
}