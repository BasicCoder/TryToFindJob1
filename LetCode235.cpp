#include <iostream>
#include <cmath>
#include <algorithm>

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
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max_val = max(p -> val, q -> val);
        int min_val = min(p -> val, q -> val);

        TreeNode * node = root;
        while(p){
            if(node -> val > max_val)
                node = node -> left;
            if(node -> val < min_val)
                node = node -> right;
            if(node -> val <= max_val && node -> val >= min_val)
                break;
        }
        return node;
    }
};

int main(){

}