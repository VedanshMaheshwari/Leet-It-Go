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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                break;
            }
        }

        if (fast == NULL || fast->next == NULL) {  
            return NULL;
        }

        while(slow!= fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    } 
};