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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;

        ListNode* pPrePre = NULL;
        ListNode* pPre = NULL;
        ListNode* p = head;

        while(p && p -> next){
            pPre = p;
            p = p -> next;

            ListNode* pNext = p -> next;
            if(pPre == head){
                head = p;
            }

            if(pPrePre){
                pPrePre -> next = p;
            }

            p -> next = pPre;
            pPre -> next  = pNext;

            pPrePre = pPre;
            p = pNext;

        }

        return head;
    }
};

int main(){

}