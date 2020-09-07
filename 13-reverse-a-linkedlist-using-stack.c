#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 200

struct Node{
    int data;
    struct Node* next;
};

int* S[MAX_SIZE]; //stack to store pointers to int
int top = -1; //empty stack in the begining

void Push(int* number){
    if(top == MAX_SIZE -1){
        printf("Stack Overflow!");
        return;
    }
    S[++top] = number; //increment top and assign value
}

void Pop(){
    if(top == -1){
        printf("stack is empty!");
        return;
    }
    top--;
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    return newNode;
}

void Print(struct Node* head){
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}
struct Node* Reverse(struct Node* head){
    struct Node* temp = head;

    //push items in stack
    while(temp->next != NULL){
        Push(temp);
        temp = temp->next;
    }
    head = temp;
    //reset values in node and pop from stack
    while(top != -1){
        temp->next = S[top];
        temp = temp->next;
        Pop();
    }
    temp->next = NULL;
    return head;
}

struct Node* Insert(struct Node* head, int number){
    struct Node* newNode = GetNewNode(number);

    if(head == NULL){
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

void main(){
    struct Node* head = NULL;
    int i,total,number;

    printf("how many numbers you want to insert?");
    scanf("%d",&total);

    for (i=0; i<total; i++){
        printf("enter a number");
        scanf("%d",&number);
        head = Insert(head,number);
    }
    Print(head);
    head = Reverse(head);
    Print(head);
}
