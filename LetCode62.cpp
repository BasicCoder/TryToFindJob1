#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <=0 || n <= 0) return 0;
        
        vector< vector<int> > sum(m, vector<int>(n, 1));
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                sum[i][j] = sum[i -1][j] + sum[i][j -1];
            }
        }

        return sum[m -1][n -1];
    }
};

int main(){
        int m, n;
        cin >> m >> n;

        Solution solution;
        cout << solution.uniquePaths(m, n) << endl;
}