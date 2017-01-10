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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = head;
        
        if(head == NULL || head -> next == NULL) return pre;

        ListNode* p = pre -> next;

        while(p){
            ListNode* temp = p -> next;
            p -> next = pre;
            pre = p;
            p = temp;
        }
        head -> next = NULL;
        return pre;

    }
};

int main(){

}
