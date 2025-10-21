#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;

        // Step 1: Check if there are at least k nodes to reverse
        ListNode* temp = head;
        int count = 0;
        while (temp != NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (count < k) return head;  // not enough nodes, return as is

        // Step 2: Reverse k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        count = 0;

        while (curr != NULL && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: Recursively call for the remaining list
        if (next != NULL) {
            head->next = reverseKGroup(next, k);
        }

        // Step 4: Return new head
        return prev;
    }
};
