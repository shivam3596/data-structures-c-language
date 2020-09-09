#include<stdio.h>
#include<stdlib.h>

//in linkedlist implementation of queue, we keep 2 pointers front and rear
struct Node* front = NULL;
struct Node* rear = NULL;

struct Node{
    int data;
    struct Node* next;
};

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    return newNode;
}

void Dequeue(){
    struct Node* temp = front;

    if(front == NULL && rear == NULL){
        printf("queue is empty!");
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
    }
    free(temp);
    return;
}

void Enqueue(int number){
    struct Node* newNode = GetNewNode(number);

    if(front == NULL && rear == NULL){
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    return;
}

void Print(){
    struct Node* temp = front;
    while(temp != NULL){
        printf("%d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void main(){
    int total,i,number;
    printf("how many numbers you want to insert in queue: ");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter number: ");
        scanf("%d",&number);
        Enqueue(number);
    }
    Print();
    Dequeue();
    Dequeue();
    Print();
}
