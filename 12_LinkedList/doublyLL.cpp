#include<iostream>
using namespace std;

class node{
    public:
    node *prev;
    int data;
    node *next;

    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    //freeing memory for deletion of node
    ~node(){
        if(this->next != NULL){
            delete next;
            //this is for safety purpose althought the memory is already freed
            //but we are making sure that the pointer is not pointing to any garbage value
            this->next = NULL;
        }
    }
};

void insertAtHead(node* &head, node *&tail,int data){

    if(head == NULL){
        node * temp = new node(data);
        head = temp;
        tail = temp;
        return;
    }
    node * temp = new node(data);
    temp->next = head;
    head->prev = temp;
    head = temp; 
}

void insertAtTail(node *&head, node *&tail, int data){
        if(tail == NULL){
        node * temp = new node(data);
        tail = temp;
        head = temp;
        return;
    }
    node *temp = new node(data);
    temp->next = NULL;
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(node* &head, node* &tail, int position, int data){
    if(position == 1){
        insertAtHead(head , tail,  data);
        return;
    }

    node *temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(head, tail , data);
        return;
    }

    node * newNode = new node(data);
    
    newNode->next = temp->next;
    temp->next->prev = newNode;

    newNode->prev = temp;
    temp->next = newNode;

}

void deleteNode(int position, node* & head, node* &tail){
    if (position==1){
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp; 
    }
    else{

        node *curr = head;
        node* prev = NULL;
        int count = 1;
        
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }

        if(curr->next == NULL){
            tail = prev;
        }

        curr->prev = NULL;
        prev->next = curr->next;
       // curr->next->prev = prev;
        curr->next = NULL;
        delete curr;


    }

}
 
void print(node * &head){
    node * temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){

    //node *n = new node(1);
    node *head = NULL;
    node *tail = NULL;
    insertAtHead(head,tail,0);
    insertAtHead(head,tail,-1);
    insertAtTail(head,tail,1);
    insertAtPosition(head,tail,4,2);
    print(head);
    cout << endl;
    deleteNode(1,head,tail);
    print(head);
}

