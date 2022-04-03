#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
}

void insertAtFront(Node* *head, int d){

    Node* ptr = new Node();
    ptr->data = d;
    ptr->next = *head;
    *head = ptr;
}

void insertAtEnd(Node* *head, int d){
    Node* ptr = new Node();
    Node* temp = *head;
    ptr->data = d;
    ptr->next = NULL;
    if (*head == NULL){
        *head = ptr;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;
}

void insertAfter(Node *previous, int d){
    if (previous == NULL){
        return;
    }
    Node *ptr = new Node();
    ptr->data = d;
    ptr->next = previous->next;
    previous->next = ptr;
}

int main(){
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    insertAtFront(&head, 0);
    insertAtEnd(&head, 4);
    insertAfter(head, -1);
    printList(head);

    return 0;
}



