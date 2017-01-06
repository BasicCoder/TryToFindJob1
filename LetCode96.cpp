#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
// 首先想到卡塔兰数， 公式看起来很容易理解，但是long long int 都没法搞定
class Solution0 {
private:
	long long int decreMul(int m, int n){
		long long int  result = 1;
		while(m >= n){
			result *= m;
			--m;
		}
		return result;
	}
public:
    int numTrees(int n) {
    	long long int a = decreMul(2*n, n+1);
    	long long int b = ( (n+1) * decreMul(n, 1));
    	cout << a << ' ' << b << endl;
        return decreMul(2*n, n+1) / ( (n+1) * decreMul(n, 1));
    }
};

class Solution{
private:
	int result[30]; //准确的说是前20项，20项以后应该超出int表示范围
public:
	Solution(){
		for(int i = 0; i <= 30; ++i){
			result[i] = 0;
		}
		result[0] = 1;
		result[1] = 1;
		for(int i = 2; i <= 30; ++i){
			for(int j = 0; j < i; ++j){
				result[i] += result[j] * result[i - 1 - j];
			}
		}
		/*for(int i = 0; i <= 30; ++i)
			cout << result[i] << ' ';
		cout << endl;
		*/
	}
public:
	int numTrees(int n) {
		if(n <= 0) return 0;
		return result[n];
	}
};

int main(){
	int N;
	cin >> N;
	Solution solution;
	while(N){
		cout << solution.numTrees(N) << endl;
		cin >> N;
	}
}
