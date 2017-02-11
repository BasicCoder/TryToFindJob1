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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return head;
        ListNode* tail = head;
        int n = 1;
        while(tail -> next != NULL){
            ++n;
            tail = tail -> next;
        }

        k %= n;

        if(k == 0)
            return head;
        
        int len = n - k;
        ListNode* cur = head;
        while(--len){
            cur = cur -> next;
        }
        ListNode* post = cur -> next;
        cur -> next = NULL;
        tail -> next = head;
        return post;
    }
};


int main(){
    
}