#include <iostream>
#include <vector>
#include <algorithm>
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
// 这道题思路是对着，但是时间性能不好，有一步将level数组完全copy过去，这个时间花费开销有点大，
// 应该直接先将空的level加入，之后直接在level后面添加数据，避免了copy.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
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

        int size = result.size();
        for(int i = 0; i < size; ++i){
            if(i % 2 == 1){
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};

//这一步简化直接少一半时间
class Solution {
public:
    vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector< vector<int> > result;
        if(root == NULL) return result;

        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int index = 0;
        result.push_back(level);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            if(p != NULL){
                result[index].push_back(p -> val);
                if(p -> left != NULL){
                    q.push(p -> left);
                }
                if(p -> right != NULL){
                    q.push(p -> right);
                }
            }else{
                if(!q.empty()){
                    q.push(NULL);
                    result.push_back(level);
                    ++index;                  
                }
                level.clear();        
            }
        }

        int size = result.size();
        for(int i = 0; i < size; ++i){
            if(i % 2 == 1){
                reverse(result[i].begin(), result[i].end());
            }
        }
        return result;
    }
};

int main(){
    
}
