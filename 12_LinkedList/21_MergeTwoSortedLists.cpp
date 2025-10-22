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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        // Dummy head to build merged list
        ListNode* head = new ListNode(0);
        ListNode* temp = head;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        while (t1 != NULL && t2 != NULL) {
            if (t1->val == t2->val) {
                temp->next = new ListNode(t1->val);
                temp = temp->next;
                temp->next = new ListNode(t2->val);
                temp = temp->next;

                t1 = t1->next;
                t2 = t2->next;
            }
            else if(t1->val < t2->val) {
                temp->next = new ListNode(t1->val);
                temp = temp->next;
                t1 = t1->next;
            }
            else{
                temp->next = new ListNode(t2->val);
                temp = temp->next;
                t2 = t2->next;
            }
        }

        while(t1 != NULL){
            temp->next = new ListNode(t1->val);
            temp = temp->next;
            t1 = t1->next;
        }

        while(t2 != NULL){
            temp->next = new ListNode(t2->val);
            temp = temp->next;
            t2 = t2->next;
        }

        return head->next;
    }
};
