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
private:
    void reverseList(ListNode* &head){
        if(head == NULL || head -> next == NULL) return;
        ListNode* pre = head, *p = pre -> next;
        while(p != NULL){
            ListNode* tmp = p -> next;
            p -> next = pre;
            pre = p;
            p = tmp;
        }
        head -> next = NULL;
        head = pre;
    }
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL) return head;
        if(m == n)return head;
        ListNode* pre = NULL, *p = head;
        ListNode* back = NULL;
        
        int cnt = m - 1;
        while(cnt >= 1 ){
            --cnt;
            pre = p;
            p = p -> next;       
        }

        cnt = n - m;
        back = p;
        while(cnt > 0){
            back = back -> next;
            --cnt;
        }
        ListNode* tmp1 = NULL , *tmp = NULL, *tmp2 = NULL;
        if(pre == NULL){
            tmp1 = p;
            tmp2 = back -> next;
            back -> next = NULL;
            reverseList(p);

            tmp1 -> next = tmp2;
            head = p;
            return head;
        }else{
            tmp1 = p;
            pre -> next = NULL;
            tmp2 = back -> next;
            back -> next = NULL;
            reverseList(p);

            pre -> next = p;
            tmp1 -> next = tmp2;
            return head;
        }
        return head;
       
    }
};

int main(){
    int m,n;
    int N;
    cin >> N;
    int a;
    ListNode * head = NULL;
    ListNode * tail = NULL;
    for(int i = 0; i < N; ++i){
        cin >> a;
        ListNode * p = new ListNode(a);
        if(head == NULL){
            head = p;
            tail = p;
        }else{
            tail -> next = p;
            tail = p;
        }
    }
    cin >> m >> n;
    Solution solution;
     ListNode * p = solution.reverseBetween(head, m, n);

   
    while(p){
        cout << p -> val << ' ';
        p = p -> next;
    }
    cout << endl;
}
