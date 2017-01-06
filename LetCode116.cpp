/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return ;
        queue<TreeLinkNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeLinkNode * p = q.front();
            q.pop();
            if(p != NULL){
                if(!q.empty()) p -> next = q.front();
                if(p -> left)
                    q.push(p -> left);
                if(p -> right)
                    q.push(p -> right);
            }else{
                if(q.size() > 1) //题目的描述假定了条件限制是perfect tree.
                    q.push(NULL);
            }
        }
    }
};

int main(){
    
}