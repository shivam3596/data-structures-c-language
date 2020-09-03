
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

void Print(struct Node* head){
    //exit condition
    if(head == NULL){
        return;
    }
    printf("%d",head->data); //print value of the current node
    Print(head->next); //pass address of the next node as a recursive call
}

struct Node* Reverse(struct Node* head){
    //exit condition
    if(head->next == NULL){
        return head;
    }
    struct Node* p = Reverse(head->next);
    struct Node* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return p;
}

struct Node* Insert(struct Node* head,int x,int n){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    //when need to insert at first position
    if(n==1){
        newNode->next = head;
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    for(int i=1; i< n-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void main(){
    struct Node* head = NULL; //empty list
    head = Insert(head,2,1);
    head = Insert(head,3,2);
    head = Insert(head,4,3);
    head = Insert(head,5,4);
    Print(head);
    printf("\n");
    head = Reverse(head);
    Print(head);
}
