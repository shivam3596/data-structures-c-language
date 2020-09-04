#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void Print(struct Node* head){
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

void ReversePrint(struct Node* head){
    while(head->next != NULL){
        head = head->next;
    }
    printf("Reverse Order:");
    while(head != NULL){
        printf("%d",head->data);
        head = head->prev;
    }
    printf("\n");
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct Node* InsertAtHead(struct Node* head, int number){
    struct Node* newNode = GetNewNode(number);
    if(head == NULL){
        head = newNode;
        return head;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* InsertAtTail(struct Node* head, int number){
    struct Node* newNode = GetNewNode(number);
    struct Node* temp = head;
    if(head == NULL){
        head = newNode;
        return head;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void main(){
    struct Node* head = NULL;
    int number,i,total;
    printf("how many numbers you want to insert");
    scanf("%d",&total);
    for(i=0; i < total ; i++){
        printf("enter a number to insert");
        scanf("%d",&number);
        head = InsertAtTail(head,number);
    }
    Print(head);
    ReversePrint(head);
}
