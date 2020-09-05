#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

void Print(struct Node* head){
    struct Node* first = head;

    if(head != NULL){
        do{
            printf("%d",head->data);
            head = head->next;
        }
        while(first != head);
        printf("\n");
    }
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
    struct Node* temp = head;
    if(head != NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head = newNode;
    }else{
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    }
    return head;
}

void main(){
    struct Node* head = NULL;
    int total,i,number;

    printf("how many numbers you want to insert");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number:");
        scanf("%d",&number);
        head = InsertAtHead(head,number);
    }
    Print(head);
}
