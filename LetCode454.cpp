#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
private:
    void workmap(vector<int>& A, vector<int>& B, unordered_map<int, int>& m){
        int size = A.size();
        for(int i = 0; i < size; ++i){
            for(int j = 0; j < size; ++j){
                ++m[ A[i] + B[j] ];
            }
        }
    }
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m1, m2;
        workmap(A, B, m1);
        workmap(C, D, m2);
        int res = 0;
        unordered_map<int, int>::iterator it1 = m1.begin();
        for( ; it1 != m1.end(); ++it1){
            unordered_map<int, int>::iterator it2 = m2.find(-it1 -> first);
            if(it2 != m2.end())
                res += it1 -> second * it2 -> second;
        }
        return res;
    }
};

int main(){
    
}
