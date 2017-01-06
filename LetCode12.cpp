#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;


class Solution{
	public:
	Solution(){
	};
	~Solution(){
	};
	
	public:
		string inToRoman(int num){
			string result;
			char *roman[][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
								 "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
								 "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
								 "", "M", "MM", "MMM"};
			int i, j, n;
			for(j = 0, i = 10000; j < 4; ++j, i/=10){
				n = (num % i) / (i / 10);
				result += roman[3-j][n];
			}
			
			return result;
		}
}; 

int main(){
	int n;
	Solution solution;
	while( scanf("%d", &n) && n ){
		cout << solution.inToRoman(n) << endl;
	}
}
