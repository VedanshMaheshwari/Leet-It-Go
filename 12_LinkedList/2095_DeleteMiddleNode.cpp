#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev = NULL;

        while(fast != NULL &&  fast->next != NULL){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next; 
        }

        prev->next = slow->next;
        return head;
    }
};