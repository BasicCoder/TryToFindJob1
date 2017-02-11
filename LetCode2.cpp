#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* res = NULL,  *pNode = NULL, *pNext = NULL;
        ListNode* p = l1, *q = l2;
        int flag = 0;

        while(p != NULL && q != NULL){
            pNext = new ListNode(p -> val + q -> val + flag);
            flag = pNext -> val / 10;
            pNext -> val %= 10;

            if(res == NULL){
                res = pNode = pNext;
            }else{
                pNode -> next = pNext;
                pNode = pNext;
            }

            p = p -> next;
            q = q -> next;
        }

        while( p != NULL){
            pNext = new ListNode(p -> val + flag);
            flag = pNext -> val / 10;
            pNext -> val %= 10;

            pNode -> next = pNext;
            pNode = pNext;
            p = p -> next;
        }

        while(q != NULL){
            pNext = new ListNode(q -> val + flag);
            flag = pNext -> val / 10;
            pNext -> val %= 10;

            pNode -> next = pNext;
            pNode = pNext;
            q = q -> next;
        }

        if(flag > 0){
            pNext = new ListNode(flag);
            pNode -> next = pNext;
        }

        return res;
    }
};


int main(){
    
}