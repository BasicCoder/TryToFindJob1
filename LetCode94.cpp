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
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int> result;
private:
    void inorder(TreeNode * root){
        if(root != NULL){
            inorder(root -> left);
            result.push_back(root -> val);
            inorder(root -> right);
        }    
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return result;
    }
};

int main(){
    
}
