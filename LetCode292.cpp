#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
//博弈论里面游戏:
//  1个石子，先手全部拿走；
//  2个石子，先手全部拿走；
//  3个石子，先手全部拿走；
//  4个石子，后手面对的是先手的第1，2，3情况，后手必胜；
//  5个石子，先手拿走1个让后手面对第4种情况，后手必败；
//  6个石子，先手拿走2个让后手面对第4种情况，后手必败；
//  ……
//  容易看出来，只有当出现了4的倍数，先手无可奈何，其余情况先手都可以获胜。
// （石子数量为4的倍数）后手的获胜策略十分简单，每次取石子的数量，与上一次先手取石子的数量和为4即可；
// （石子数量不为4的倍数）先手的获胜策略也十分简单，每次都令取之后剩余的石子数量为4的倍数（4*0=0，直接拿光），
//  他就处于后手的位置上，利用上一行的策略获胜。
class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0)return false;
        else return true;
    }
};

int main(){

}