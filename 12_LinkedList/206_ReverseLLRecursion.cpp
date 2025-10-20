struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void reverse(ListNode * &prev, ListNode * &head, ListNode * &curr){
    if(curr == NULL){
        head = prev;
        return;
    }

    ListNode *front = curr->next;   
    reverse( curr, head, front);
    curr->next = prev;
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;

        reverse(prev,head,curr);
        return head;
    }
};