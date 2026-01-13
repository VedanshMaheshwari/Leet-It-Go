#include<iostream>
#include<algorithm>
#include<vector>
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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        int c = 0;
        while (temp) {
            c++;
            temp = temp->next;
        }

        if (head->next == nullptr)
            return true;

        // Move to middle
        c /= 2;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (c--) {
            prev = curr;
            curr = curr->next;
        }

        // Split into two halves
        prev->next = nullptr;

        // Reverse second half
        prev = nullptr;
        ListNode* front = nullptr;
        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        // Compare two halves
        ListNode* head1 = head;
        ListNode* head2 = prev;

        while (head1 && head2) {
            if (head1->val != head2->val)
                return false;
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }
};

class Solution {
public:

    ListNode *reverseRecurr(ListNode *head){
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *newNode = reverseRecurr(head->next);

        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;

        return newNode;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
    
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = reverseRecurr(slow->next);

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = secondHalf;

        while(second != NULL){
            if(first->val != second->val){
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};