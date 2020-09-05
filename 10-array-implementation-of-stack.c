#include<stdio.h>
#define MAX_SIZE 100

int A[MAX_SIZE];
int top = -1; //empty stack in the begining

void Push(int element){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow:");
        return;
    }
    A[++top] = element; //increment the top and insert value
}

void Pop(){
    if(top == -1){
        printf("Stack is empty:");
        return;
    }
    top--;
}

int Top(){
    //return the element at the top of the stack
    return A[top];
}

int IsEmpty(){
    if(top == -1){
        printf("is empty : yes");
    }else{
        printf("is empty: no");
    }
    printf("\n");
    return;
}

void Print(){
    printf("stack is:");
    for(int i=0; i<= top; i++){
        printf("%d",A[i]);
    }
    printf("\n");
}

void main(){
    IsEmpty();
    Push(2);
    Push(3);
    Push(4);
    Push(5);
    Print();
    Pop();
    Pop();
    Print();
    IsEmpty();
}
