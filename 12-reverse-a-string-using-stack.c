#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define MAX_SIZE 200

char S[MAX_SIZE];
int top = -1; //empty stack in the begining

void Push(char element){
    if(top == MAX_SIZE - 1){
        printf("stack overflow !");
        return;
    }
    S[++top] = element;
}

void Pop(){
    if(top == -1){
        printf("stack is empty");
        return;
    }
    top--;
}

void Reverse(char* C, int length){
    //push in stack
    for(int i=0; i<length; i++){
        Push(C[i]);
    }

    for(int j=0; j<length; j++){
        C[j] = S[top]; //set string character as top of stack // override array characters
        Pop();
    }
}

void main(){
    char C[MAX_SIZE];
    printf("enter the string");
    scanf("%s",C);
    Reverse(C,strlen(C));
    printf("%s",C);
}
