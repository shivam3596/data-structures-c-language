#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <limits.h>
#define COUNT 10

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Print(struct Node* root, int space){
    if(root == NULL) return;

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
    }else if(number <= root->data){
        root->left = Insert(root->left,number);
    }else{
        root->right = Insert(root->right,number);
    }
    return root;
}

bool IsBstUtil(struct Node* root,int min, int max){
    if(root == NULL) return true;

    if(root->data > min && root->data < max && IsBstUtil(root->left,min,root->data) && IsBstUtil(root->right,root->data,max)){
        return true;
    }else{
        return false;
    }
}

bool IsBinarySearchTree(struct Node* root){
    return IsBstUtil(root,INT_MIN,INT_MAX);
}

void main(){
    struct Node* root = NULL;
    int total,i,number;

    printf("How many numbers you want to insert in tree?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    if(IsBinarySearchTree(root)){
        printf("Yes");
    }else{
        printf("No");
    }
}
