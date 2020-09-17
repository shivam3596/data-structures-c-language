#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
#define COUNT 10

struct Node* Stack[MAX_SIZE];
int top = -1; //empty stack in the begining

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void Push(struct Node* item){
    if(top == MAX_SIZE -1){
        printf("stack overflow");
        return;
    }
    Stack[++top] = item;
}

void Pop(){
    if(top == -1){
        printf("stack is empty");
        return;
    }
    top--;
}

bool IsEmpty(){
    return top == -1 ? true : false;
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void IterativePreOrder(struct Node* root){
    if(root == NULL) return; //base case

    Push(root);

    while(!IsEmpty()){
        struct Node* current = Stack[top];
        printf("%d",current->data);
        Pop();
        if(current->right != NULL) Push(current->right);
        if(current->left != NULL) Push(current->left);
    }

}

void Print(struct Node* root,int space){
    if(root == NULL){
        return;
    }

    space += COUNT;

    Print(root->right,space);
    printf("\n");

    for(int i=0; i<space; i++){
        printf(" ");
    }

    printf("%d\n",root->data);

    Print(root->left,space);
}

struct Node* Insert(struct Node* root, int number){
    struct Node* newNode = GetNewNode(number);

    if(root == NULL){
        root = newNode;
    }else if(number < root->data){
        root->left = Insert(root->left,number);
    }else{
        root->right = Insert(root->right,number);
    }
    return root;
}

void main(){
    struct Node* root = NULL;
    int total,i,number;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number:");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    IterativePreOrder(root);
}
