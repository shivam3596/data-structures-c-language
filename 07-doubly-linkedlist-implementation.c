#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* Delete(struct Node* head, int position){
    struct Node* temp = head;
    if(position == 1){
        head = temp->next;
        free(temp);
        return head;
    }
    for(int i=1; i < position-1; i++){
        temp = temp->next; // (n-1)th node
    }

    struct Node* temp1 = temp->next; // nth node
    struct Node* temp2 = temp1->next; // (n+1)th node

    temp->next = temp1->next;
    temp2->prev = temp1->prev;
    free(temp1);
    return head;
}

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

    //delete node code below
    int deletePosition;
    printf("enter the postion you want to delete");
    scanf("%d",&deletePosition);
    head = Delete(head,deletePosition);
    Print(head);
}
