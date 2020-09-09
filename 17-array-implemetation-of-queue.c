#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 200

//Queue, FIFO (First-In-First-Out)

//Here we have used a circular array for queue

int Q[MAX_SIZE];
int front = -1;
int rear = -1;

bool IsEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

void Dequeue(int total){
    if(IsEmpty()){
        printf("queue is empty!");
        return;
    }else if(front == rear){ //check if there is only single element in queue
        front = -1;
        rear = -1;
    }else{
        front = (front+1)%total; //increment front
    }
}

void Enqueue(int number,int total){
    //check if queue is full , if next element of rear is front then queue is full
    if((rear + 1)%total == front){
        printf("Queue is full!");
        return;
    }else if(IsEmpty()){
        front = 0;
        rear = 0;
    }else{
        rear = (rear+1)%total; //increment rear
    }
    Q[rear] = number;
}

void Print(){
    printf("Queue is: ");
    //queue is only present between front and rear indexes
    for(int i=front; i<=rear; i++){
        printf("%d",Q[i]);
    }
    printf("\n");
}

void main(){
    int total,i,number;
    printf("how many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        Enqueue(number,total);
    }
    Print();
    Dequeue(total);
    Dequeue(total);
    Print();
}
