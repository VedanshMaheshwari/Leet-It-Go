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
    bool hasCycle(ListNode *head) {
        ListNode *temp = head; 
        unordered_map<ListNode *, bool>visited;;

        while(temp != NULL){

            if(visited[temp] == true){
                return true;
            }

            visited[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            //if(fast != NULL) fast = fast->next;
            slow = slow->next;
            if(slow == fast){
                return true;
            }

        }

        return false;
    }
};