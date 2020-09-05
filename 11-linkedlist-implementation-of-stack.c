#include<stdlib.h>
#include<stdio.h>

//linked list implementation of stack is simillar to insert/delete at head of linkedlist

struct Node{
    int data;
    struct Node* next;
};

void Print(struct Node* head){
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}


struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    return newNode;
}

struct Node* Push(struct Node* head, int number){
    struct Node* newNode = GetNewNode(number);

    if(head == NULL){
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* Pop(struct Node* head){
    struct Node* temp = head;
    if(head == NULL){
        return;
    }
    head = head->next;
    free(temp);
    return head;
}

void main(){
    struct Node* head = NULL;
    int total,i,number;

    printf("how many numbers you want to enter");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter number");
        scanf("%d",&number);
        head = Push(head,number);
    }
    Print(head);
    head = Pop(head);
    Print(head);
}
