#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 200
#define COUNT 10

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* Stack1[MAX_SIZE];
struct Node* Stack2[MAX_SIZE];
int top1 = -1;
int top2 = -1;

void PushStack1(struct Node* root){
    if(top1 == MAX_SIZE -1){
        printf("stack overflow");
        return;
    }
    Stack1[++top1] = root;
}

void PushStack2(struct Node* root){
    if(top2 == MAX_SIZE -1){
        printf("stack overflow");
        return;
    }
    Stack2[++top2] = root;
}

void PopStack1(){
    if(top1 == -1){
        printf("stack is empty");
        return;
    }
    top1--;
}

void PopStack2(){
    if(top2 == -1){
        printf("stack is empty");
        return;
    }
    top2--;
}

bool IsEmptyStack1(){
    return top1 == -1 ? true : false;
}

bool IsEmptyStack2(){
    return top2 == -1 ? true : false;
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Print(struct Node* root,int space){
    if(root == NULL) return;

    space += COUNT;
    printf("\n");

    Print(root->right,space);

    for(int i=0 ; i<space; i++){
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
        root ->left = Insert(root->left,number);
    }else{
        root->right = Insert(root->right,number);
    }
    return root;
}

void PostOrderIterative(struct Node* root){
    if(root == NULL) return;
    struct Node* node;

    //push root in stack1
    PushStack1(root);

    while(!IsEmptyStack1()){
        // Pop an item from s1 and push it to s2
        node = Stack1[top1];
        PopStack1();
        PushStack2(node);

        // Push left and right children of removed item to s1
        if(node->left != NULL){
            PushStack1(node->left);
        }
        if(node->right != NULL){
            PushStack1(node->right);
        }
    }

    // Print all elements of second stack
    while(!IsEmptyStack2()){
        node = Stack2[top2];
        PopStack2();
        printf("%d",node->data);
    }
}

void main(){
    struct Node* root = NULL;
    int total,i,number;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    PostOrderIterative(root);
}
