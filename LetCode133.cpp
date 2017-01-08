#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode* result = NULL;
        if(node == NULL) return result;
        
        map<int, UndirectedGraphNode*> nodes;
        queue<UndirectedGraphNode*> q;

        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode* p = q.front();
            q.pop();

            if(nodes.find(p -> label) == nodes.end()){
                UndirectedGraphNode* new_node = new UndirectedGraphNode(p -> label);
                nodes.insert(pair<int, UndirectedGraphNode*>(p -> label, new_node));
                int size = p -> neighbors.size();
                for(int i = 0; i < size; ++i){
                    q.push(p -> neighbors[i]);
                }
            }
        }
        q.push(node);
        while(!q.empty()){
            UndirectedGraphNode* p = q.front();
            q.pop();

            UndirectedGraphNode* node = nodes[p -> label];
            if(node -> neighbors.empty() && !p -> neighbors.empty()){
                int size = p -> neighbors.size();
                for(int i = 0; i < size; ++i){
                    node -> neighbors.push_back(nodes[p -> neighbors[i] -> label]);
                    q.push(p -> neighbors[i]);
                }
            }

        }
        return nodes[node -> label];
    }
};

int main(){

}
