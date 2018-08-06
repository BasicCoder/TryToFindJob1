#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()){
        	return s.empty();
		}
		
		if(p.length() == 1 || p[1] != '*'){
			if(s.empty() || (p[0] != '.' && p[0] != s[0])){
				return false;
			}else{
				return isMatch(s.substr(1), p.substr(1));
			}
		}
		
		while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
			if(isMatch(s, p.substr(2))){
				return true;
			}
			s = s.substr(1);
		}
		
		return isMatch(s, p.substr(2));
    }
};

int main(){
	Solution solution = Solution();
	string s = "aab";
	string p = "c*a*b";
	cin >> s >> p;
	
	cout << solution.isMatch(s, p) << endl;
}
