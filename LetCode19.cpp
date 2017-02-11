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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        ListNode* pPre = NULL;
        ListNode* p = head;
        ListNode* q = head;

        for(int i = 0; i < n - 1; ++i){
            q = q -> next;
        }
        while(q -> next){
            pPre = p;
            p = p -> next;
            q = q -> next;
        }

        if(pPre == NULL){
            head = p -> next;
            delete p;
        }else{
            pPre -> next = p -> next;
            delete p;
        }

        return head;
    }
};


int main(){
    
}