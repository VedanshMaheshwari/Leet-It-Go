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
    ListNode* deleteDuplicates(ListNode* head) {  
        if(head == NULL){
            return head;
        }
        
        ListNode *temp = head;
        while(temp != NULL && temp->next != NULL){
            if(temp->val == temp->next->val){
                ListNode *front = temp->next;
                temp->next = front->next;
                delete front;
            }
            else{
                temp = temp->next;
            }
        }
        return head;
    }
};