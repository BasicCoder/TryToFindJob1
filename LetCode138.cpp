#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

struct RandomListNode {
     int label;
     RandomListNode *next, *random;
     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};



class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        map<RandomListNode *, RandomListNode*>relation;
        RandomListNode* dst = NULL;
        RandomListNode* pdst = NULL;
        RandomListNode* p = head;

        while(p){
            RandomListNode* new_node = new RandomListNode(p -> label);
            relation.insert(pair<RandomListNode*, RandomListNode*>(p, new_node));
            if(dst == NULL){
                dst = new_node;
                pdst = new_node;
            }else{
                pdst -> next = new_node;
                pdst = pdst -> next;
            }
            pdst -> random = p -> random;
            p = p -> next;
        }

        p = head;
        pdst = dst;
        while(p){
            if(p -> random != NULL){
                pdst -> random = relation[p -> random];
            }else{
                pdst -> random = NULL;
            }
            pdst = pdst -> next;
            p = p -> next;
        }
        
        return dst;
   }
};

int main(){
    
}