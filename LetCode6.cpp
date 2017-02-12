#include <iostream>
#include <vector>
#include <string>


using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if(len == 0 || numRows <= 1) return s;

        string lines[numRows];

        int row = 0, delta = 1;
        for(int i = 0; i < len; ++i){
            lines[row] += s[i];
            row += delta;
            if(row >= numRows){
                row = numRows - 2;
                delta = -1;
            }
            if(row < 0){
                row = 1;
                delta = 1;
            }
        }

        string res;
        for(int i = 0; i < numRows; i++){
            res += lines[i];
        }
        return res;

    }
};

int main(){

}
