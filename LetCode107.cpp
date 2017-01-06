/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        ret.clear();
        if(root == NULL) return ret;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> temp;

        while( !q.empty() ){
            TreeNode* p = q.front();
            q.pop();
            if( p != NULL){
                temp.push_back(p -> val);
                if( p -> left != NULL){
                    q.push(p -> left);
                }
                if( p -> right != NULL){
                    q.push(p -> right);
                }
            }else{
                if( !temp.empty() ){
                    q.push(NULL);
                    ret.push_back(temp);
                    temp.clear();
                }
            }
        }

        reverse(ret.begin(), ret.end());
        return ret;
    }
};

int main(){
    
}