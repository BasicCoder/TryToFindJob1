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
private:
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode * l = new ListNode(0), *p = l;
        while(l1 != NULL && l2 != NULL){
            if(l1 -> val < l2 -> val){
                p -> next = l1;
                l1 = l1 -> next;
            }else{
                p -> next = l2;
                l2 = l2 -> next;
            }
            p = p -> next;
        }

        if(l1 != NULL)
            p -> next = l1;
        if(l2 != NULL)
            p -> next = l2;
        return l -> next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        ListNode* pre = NULL, *slow = head, *fast = head;

        while(fast != NULL && fast -> next != NULL){
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        pre -> next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return merge(l1, l2);
    }
};


int main(){
    
}
