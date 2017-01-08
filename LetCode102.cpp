#include <iostream>
#include <vector>
#include <alogrithm>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root == NULL) return result;

        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p != NULL){
                level.push_back(p -> val);
                if(p -> left != NULL){
                    q.push(p -> left);
                }
                if(p -> right != NULL){
                    q.push(p -> right);
                }
            }else{
                if(!q.empty()){
                    q.push(NULL);                  
                }
                result.push_back(level);
                level.clear();        
            }
        }
        return result;
    }
};


int main(){
    
}