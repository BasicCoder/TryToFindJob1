#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
private:
    class Pos{
    public:
        int x;
        int y;
    public:
        Pos(int _x, int _y):x(_x),y(_y){}
    };
private:
    void bfs(vector< vector<char> >& board, int x, int y){
        int row = board.size();
        int column =  board[0].size();

        queue<Pos*> q;
        board[x][y] = 'Y';
        Pos* pos = new Pos(x, y);
        q.push(pos);

        while(!q.empty()){
            Pos* p = q.front();
            q.pop();

            if(p -> x > 0 && board[p -> x -1][p -> y] == 'O'){
                Pos * up = new Pos(p -> x -1, p -> y);
                q.push(up);
                board[up -> x][up -> y] = 'Y';
            }

            if(p -> x < row - 1 && board[p -> x + 1][p -> y] == 'O'){
                Pos * down = new Pos(p -> x +1, p -> y);
                q.push(down);
                board[down -> x][down -> y] = 'Y';
            }

            if(p -> y > 0 && board[p -> x][p -> y -1] == 'O'){
                Pos * left = new Pos(p -> x, p -> y -1);
                q.push(left);
                board[left -> x][left -> y] = 'Y';
            }

            if(p -> y < column -1 && board[p -> x][p -> y +1] == 'O'){
                Pos * right = new Pos(p -> x , p -> y +1);
                q.push(right);
                board[right -> x][right -> y] = 'Y';
            }
        }
    }
public:
    void solve(vector< vector<char> >& board) {
        if(board.empty() || board[0].empty())
            return;
        int row = board.size();
        int column =  board[0].size();
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                if(board[i][j] == 'O'){
                    if(i == 0 || i == row -1 || j == 0 || j == column -1){
                        bfs(board, i, j);
                    }
                }
            }
        }

        for(int i = 0; i < row; ++i){
            for(int j = 0; j < column; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                if(board[i][j] == 'Y')
                    board[i][j] = 'O';
            }
        }

    }
};

int main(){
    
}
