#include<bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* GetNewNode(int d){
    Node* newNode = new Node();
    newNode->data = d;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void insertAtFront(Node* *head, int d){

    Node* ptr = GetNewNode(d);
    ptr->next = *head;
    *head = ptr;
}

void insertAtEnd(Node* *head, int d){
    Node* ptr = GetNewNode(d);
    Node* temp = *head;
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

    Node *ptr = GetNewNode(d);
    Node *temp = *head;
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

struct DoubleLinkedNode{
    int data;
    DoubleLinkedNode* next;
    DoubleLinkedNode* prev;
};

DoubleLinkedNode* GetNewDNode(int d){
    DoubleLinkedNode* newNode = new DoubleLinkedNode();
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->data = d;
    return newNode;
}

void DinsertAtHead(DoubleLinkedNode* *head, int d){
    DoubleLinkedNode* temp = GetNewDNode(d);
    DoubleLinkedNode* temp1 = *head;
    if (*head == NULL){
        *head = temp;
        return;
    }
    temp1->prev = temp;
    temp->next = *head;
    *head = temp;
}

void printDList(DoubleLinkedNode *head){
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    // Linked

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

    // Double Linked

    DoubleLinkedNode* Dhead = NULL;

    DinsertAtHead(&Dhead, 1);
    DinsertAtHead(&Dhead, 2);
    DinsertAtHead(&Dhead, 3);
    DinsertAtHead(&Dhead, 4);

    printDList(Dhead);

    return 0;
}



