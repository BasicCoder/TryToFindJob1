#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;

        ListNode * p = head;

        while(p){
            ListNode * temp = NULL;
            while( (p != NULL) && (p -> next != NULL) && (p -> val == p -> next -> val) ){
                temp = p -> next;
                p -> next = temp -> next;
                delete temp;
            }

            p = p -> next;
        }
        

        return head;
    }
};


int main(){
    int N;
    cin >> N;
    ListNode *head = new ListNode(N);
    ListNode *tail = head;
    int a = 0;
    for(int i = 0; i < N; ++i){
        cin >> a;
        ListNode * node = new ListNode(a);
        tail -> next = node;
        tail = node;
    }
    Solution solution;
    solution.deleteDuplicates(head -> next);
    ListNode *p = head -> next;
    while(p){
        cout << p -> val << ' ';
        p = p -> next;
    }
    cout << endl;
}