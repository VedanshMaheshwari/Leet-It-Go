#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

Node* sortList(Node *head){
    // Write your code here.
    Node *temp = head;
    
    int zero = 0;
    int one = 0;
    int two = 0;
    
    while(temp != NULL){
        if(temp->data == 0){
            zero++;
        }
        else if(temp->data == 1){
            one++;
        }    
        else if(temp->data == 2){
            two++;
        }
        temp = temp->next;
    }
    temp = head;
    while(temp != NULL){
        if(zero != 0){
            temp->data = 0;
            zero--;
        }
        else if(one != 0){
            temp->data = 1;
            one--;
        } 
        else if(two != 0){
            temp->data = 2;
            two--;
        }
        temp = temp->next;
    }

    return head;
}

void insertAtTail(Node * &tail, Node * curr){
    tail->next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    if (head == NULL || head->next == NULL) return head;

    Node *hzero = new Node(-1);
    Node *tzero = hzero;
    Node *hone = new Node(-1);
    Node *tone = hone;
    Node *htwo = new Node(-1);
    Node *ttwo = htwo;

    Node *curr = head;
    
    while(curr != NULL){
        if(curr->data == 0){
            insertAtTail(tzero, curr);
        } 
        else if(curr->data == 1){
            insertAtTail(tone, curr);
        } 
        else {
            insertAtTail(ttwo, curr);
        }
        curr = curr->next;
    }

    // connect 0 ? 1 or 0 ? 2
    if (hone->next != NULL) {
        tzero->next = hone->next;
    } else {
        tzero->next = htwo->next;
    }

    // connect 1 ? 2
    tone->next = htwo->next;

    // terminate list
    ttwo->next = NULL;

    // update head correctly
    head = hzero->next;

    delete hzero;
    delete hone;
    delete htwo;

    return head;
}
