#include <iostream>
#include <cmath>
#include <vector>

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

// 这个google题当时在网上引起了巨大讨论，没有仔细想，我觉得递归可以就试试，没想到过了。
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {

        if(root){
            invertTree(root -> left);
            invertTree(root -> right);
            TreeNode * tmp = root -> left;
            root -> left  = root -> right;
            root -> right = tmp;
        }
        
        return root;
    }
};

int main(){
    
}