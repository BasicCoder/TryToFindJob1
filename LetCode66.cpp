#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; --i){
            digits[i] += carry;
            if(digits[i] > 9){
                carry = digits[i] / 10;
                digits[i] -= carry * 10;
            }else{
                carry = 0;
                break;
            }
        }
        if(carry){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};

int main(){
    int N;
    vector<int> digits;
    int a;
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> a;
        digits.push_back(a);
    }
    Solution solution;
    solution.plusOne(digits);
    for(int i = 0; i < digits.size(); ++i){
        cout << digits[i];
    }
    cout << endl;
}
