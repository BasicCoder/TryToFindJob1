#include <iostream>
#include <vector>
#include <stack>
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

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;

        TreeNode *p = NULL;
        TreeNode *root = NULL;
        stack<TreeNode *> s;
        root = new TreeNode(postorder.back());
        s.push(root);
        postorder.pop_back();

        while(true){
            if(inorder.back() == s.top() -> val){
                p = s.top();
                s.pop();
                inorder.pop_back();
                if(inorder.size() == 0) break;
                if(s.size() && inorder.back() == s.top() -> val)
                    continue;
                p -> left = new TreeNode(postorder.back());
                postorder.pop_back();
                s.push(p -> left);
            }else{
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                s.top() -> right = p;
                s.push(p);
            }
        }

        return root;
    }
};

int main(){
    
}
