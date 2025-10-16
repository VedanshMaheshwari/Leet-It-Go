#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(node* &head, int data){
        node * temp = new node(data);
        temp->next = head;
        head = temp;
}

void insertAtTail(node* &tail, int data){
    node * temp = new node(data);
    temp-> next = NULL;
    tail->next = temp;
    tail = temp;    
}

void insertAtPosition(node* &head, node* &tail, int position, int data){
    
    //HEAD
    if(position == 1){
        insertAtHead(head , data);
        return;
    }   

    //MIDDLE
    node *temp = head;
    int count = 1;
    while(count < position-1){
        temp = temp->next;
        count++;
    }

    //TAIL
    if(temp->next == NULL){
        insertAtTail(tail , data);
        return;
    }

    node *newNode = new node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}


// Delete node
void deleteNode(int position, node* &head, node* &tail){
    if(position == 1){
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        node *curr = head;
        node *prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL){
            tail = prev;
        }

        prev -> next = curr->next;
        curr->next = NULL;
        delete curr;
    }

}

//traverse
void print(node * &head){
    node * temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}



int main (){
    node *node1 = new node(1);
    
    //pointing at head and tail;
    node *head = node1;
    node *tail = node1;

    insertAtHead(head , 0);
    insertAtHead(head , -1);
    insertAtTail(tail , 2);
    insertAtTail(tail , 3);
    deleteNode(1,head,tail);
    deleteNode(4,head,tail);
    print(head);


}
