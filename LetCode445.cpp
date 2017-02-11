#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>

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

        ListNode* p = l1, *q = l2;

        stack<int> s1;
        stack<int> s2;
        stack<int> res;

        while(p){
            s1.push(p -> val);
            p = p -> next;
        }

        while(q){
            s2.push(q -> val);
            q = q -> next;
        }

        int flag = 0;
        int tmp = 0;

        while(!s1.empty() && !s2.empty()){
            tmp = s1.top() + s2.top() + flag;
            flag = tmp / 10;
            tmp %= 10;
            res.push(tmp);

            s1.pop();
            s2.pop();
        }

        while(!s1.empty()){
            tmp = s1.top() + flag;
            flag = tmp / 10;
            tmp %= 10;
            res.push(tmp);

            s1.pop();
        }

        while(!s2.empty()){
            tmp = s2.top() + flag;
            flag = tmp / 10;
            tmp %= 10;
            res.push(tmp);

            s2.pop();
        }

        if(flag > 0) res.push(flag);

        ListNode* sum  = new ListNode(res.top());
        ListNode* pNode = sum;
        res.pop();

        while(!res.empty()){
            ListNode* node = new ListNode(res.top());
            pNode->next = node;
            pNode = pNode -> next;
            res.pop();
        } 

        return sum;
    }
};

int main(){
    
}
