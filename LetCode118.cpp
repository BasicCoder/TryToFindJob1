#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector< vector<int> > generate(int numRows) {
        vector< vector<int> > res;
        if(numRows <= 0) return res;

        vector<int> line1(1, 1);
        vector<int> line2(2, 1);

        if(numRows == 1){
            res.push_back(line1);
            return res;
        }
        if(numRows == 2){
            res.push_back(line1);
            res.push_back(line2);
            return res;
        }
        
        res.push_back(line1);
        res.push_back(line2);
        for(int i = 3; i <= numRows; ++i){
            vector<int> line(i, 1);
            for(int j = 1; j < i -1; ++j){
                line[j] = res[i-2][j] + res[i-2][j-1];
            }
            res.push_back(line);
        }

        return res;
    }
};


int main(){
	int a;
	cin >> a;
	Solution solution;
	solution.generate(a);
}
