#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define MAX_SIZE 200

char S[MAX_SIZE];
int top = -1;

char Postfix[MAX_SIZE];
int topOfPostFix = -1;

void AddInPostFixExpression(char item){
    if(topOfPostFix == MAX_SIZE -1){
        printf("stack overflow!");
        return;
    }
    Postfix[++topOfPostFix] = item;
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

bool IsOperand(char C)
{
    if(C >= '0' && C <= '9') return true;
    if(C >= 'a' && C <= 'z') return true;
    if(C >= 'A' && C <= 'Z') return true;
    return false;
}

bool IsOperator(char C)
{
    if(C == '+' || C == '-' || C == '*' || C == '/' || C== '$')
        return true;

    return false;
}

int IsRightAssociative(char op)
{
    if(op == '^') return true;
    return false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op)
{
    int weight = -1;
    switch (op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return weight;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2)
{
    int op1Weight = GetOperatorWeight(op1);
    int op2Weight = GetOperatorWeight(op2);

    // If operators have equal precedence, return true if they are left associative.
    // return false, if right associative.
    // if operator is left-associative, left one should be given priority.
    if(op1Weight == op2Weight){
        if(IsRightAssociative(op1)) return false;
        else return true;
    }
    return op1Weight > op2Weight ?  true: false;
}

void InfixToPostFix(char* C, int length){
    for(int i=0; i<length; i++){
        if(IsOperand(C[i])){
            AddInPostFixExpression(C[i]);
        }else if(IsOperator(C[i])){
            while(top != -1 && HasHigherPrecedence(S[top],C[i])){
                AddInPostFixExpression(S[top]);
                Pop();
            }
            Push(C[i]);
        }
    }
    while(top != -1){
        AddInPostFixExpression(S[top]);
        Pop();
    }
}

char* do_reverse(char* C, int length){
    static char reverse[MAX_SIZE];
    int i,j,k;

    for(i = 0; i < length; i++){
        k = i-1;
    }
    for(j = 0; j <= i-1; j++){
        reverse[j] = C[k];
        k--;
    }
    return reverse;
}

void main(){
    char C[MAX_SIZE];
    printf("enter a infix expression: ");
    scanf("%s",C);

    //reverse the infix expression
    //convert it into postfix expression
    //again reverse the expression to get prefix expression

    InfixToPostFix(do_reverse(C,strlen(C)),strlen(C));

    printf("prefix expression is: %s",do_reverse(Postfix,strlen(C)));
}
