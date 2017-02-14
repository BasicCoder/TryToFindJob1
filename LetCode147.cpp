#include <iostream>
#include <cmath>
#include <vector>

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL) return head;

        ListNode* sortList = new ListNode(0);
        ListNode* cur = head;
        ListNode* pre = sortList;
        ListNode* next = NULL;

        while(cur != NULL){
            next = cur -> next;
            while(pre -> next != NULL && pre -> next -> val < cur -> val){
                pre = pre -> next;
            }

            cur -> next = pre -> next;
            pre -> next = cur;

            pre = sortList;
            cur = next;
        }
        return sortList -> next;
    }
};


int main(){
    
}