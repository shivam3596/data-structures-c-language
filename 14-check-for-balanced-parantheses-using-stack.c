#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define MAX_SIZE 200

char S[MAX_SIZE]; //stack of characters
int top = -1; //empty stack in the begining

bool CheckOpenAndClose(char opening, char closing){
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}

void Push(char item){
    if(top == MAX_SIZE -1){
        printf("stack overflow!");
        return;
    }
    S[++top] = item;
}

void Pop(){
    if(top == -1){
        printf("stack is empty!");
        return;
    }
    top--;
}

bool CheckBalanced(char* C, int length){
    for(int i=0; i<length; i++){
        if(C[i] == '(' || C[i] == '{' || C[i] == '['){
            Push(C[i]);
        }else if(C[i] == ')' || C[i] == '}' || C[i] == ']'){
            if(top == -1 || !CheckOpenAndClose(S[top], C[i])){
                return false;
            }else{
                Pop();
            }
        }
    }

    //at the end , check if stack is empty or not
    return top == -1 ? true : false;
}

void main(){
    char C[MAX_SIZE];
    printf("enter the string");
    scanf("%s",C);

    if(CheckBalanced(C,strlen(C))){
        printf("Balanced!");
    }else{
        printf("Not Balanced!");
    }
}


