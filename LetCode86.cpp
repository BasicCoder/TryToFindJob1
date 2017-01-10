#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);

        ListNode* p = head;
        ListNode* p1 = head1;
        ListNode* p2 = head2;
        while(p){
        	ListNode* next = p -> next;
            if(p -> val < x){
                p1 -> next = p;
                p1 = p1 -> next;
                p1 -> next = NULL;
            }else{
                p2 -> next = p;
                p2 = p2 -> next;
                p2 -> next = NULL;
            }
            p = next;
        }

        p1 -> next = head2 -> next;
        
        return head1 -> next;
    }
};

int main(){
    
}
