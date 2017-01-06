#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

class Solution {
private:
    int equals(char a, char b){
        char c[8] = "IVXLCDM";
        int i, j;
        for(i = 0; i < 7; i++)
            if(a == c[i]) break;
        
        for(j = 0; j < 7; j++)
            if(b == c[j]) break;
        
        if(i < j){
            return -1;
        }else if(i > j){
            return 1;
        }else
            return 0;       
    }
public:
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;
        int *number = new int[s.length()];
        while(i < s.length()){
            switch(s[i]){
                case 'I':
                    number[i] = 1;
                    break;
                case 'V':
                    number[i] = 5;
                    break;
                case 'X':
                    number[i] = 10;
                    break;
                case 'L':
                    number[i] = 50;
                    break;
                case 'C':
                    number[i] = 100;
                    break;
                case 'D':
                    number[i] = 500;
                    break;
                case 'M':
                    number[i] = 1000;
                    break;
            }
            ++i;
        }

        sum = number[0];
        for(i = 1; i < s.length(); ++i){
        	if(number[i] <= number[i-1]){
        		sum += number[i];
			}else{
				sum = sum - number[i - 1] * 2 + number[i];
			}
		}

        return sum;
    }
};

int main(){
	string s;
    cin >> s;
    Solution solution;
    cout << solution.romanToInt(s) << endl;
}
