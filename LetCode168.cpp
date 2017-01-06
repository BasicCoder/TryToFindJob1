#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        if(n <= 0) return result;

        char c = 'A';
        int mod = 0;
        while(n){
            mod = (n -1) % 26;
            result.insert(result.begin(), char(mod + c));
            n = (n -1) / 26;        
        }
        return result;
    }
};

int main(){
    int n;
    cin >> n;
    Solution solution;
    while(n != 0){	
    	cout << solution.convertToTitle(n) << endl;
    	cin >> n;
	}
	
}
