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
    cout << endl;
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

void insertAt(Node* *head,int n, int d){

    Node *ptr = new Node();
    Node *temp = *head;
    ptr->data = d;
    ptr->next = NULL;
    if (*head == NULL){
        *head = ptr;
        return;
    }
    if (n == 0){
        ptr->next = *head;
        *head = ptr;
        return;
    }
    int i = 0;
    while (temp->next != NULL && i < n-1){
        temp = temp->next;
        i++;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void deleteAt(Node* *head, int n){
    Node* temp = *head;
    if (head == NULL){
        return;
    }
    if (n == 0){
        *head = temp->next;
        free(temp);
        return;
    }
    int i = 0;
    while(i < n-1){
        temp = temp->next;
        i++;
    }
    Node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}

void reverse(Node* *head){
    Node *current, *prev, *next;
    current = *head;
    prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void reversePrint(Node *head){
    if (head == NULL){
        return;
    }
    reversePrint(head->next);
    cout << head->data << " ";
}

int main(){
    Node* head = NULL;
    // Node* second = new Node();
    // Node* third = new Node();

    // head->data = 1;
    // head->next = second;
    // second->data = 2;
    // second->next = third;
    // third->data = 3;
    // third->next = NULL;

    // insertAtFront(&head, 0);
    insertAtEnd(&head, 4);
    insertAtEnd(&head, 0);
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAt(&head, 0, -1);
    // deleteAt(&head, 0);
    printList(head);
    reverse(&head);
    printList(head);
    // reversePrint(head);
    return 0;
}



