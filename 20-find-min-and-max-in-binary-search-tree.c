#include<stdio.h>
#include<stdlib.h>
#define COUNT 10;

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

int FindMin(struct Node* root){
    if(root == NULL){
        printf("Treee is empty");
        return 0;
    }
    //iterative approach
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;

    //recursive approach

    //if(root->left == NULL){
        //return root->data;
    //}
    //return FindMin(root->left);
}

int FindMax(struct Node* root){
    if(root == NULL){
        printf("Treee is empty");
        return 0;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
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
    }else if(number <= root->data){
        root->left = Insert(root->left,number);
    }else{
        root->right = Insert(root->right,number);
    }
    return root;
}

void main(){
    struct Node* root = NULL;
    int total,i,number;

    printf("how many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);
    printf("Min Element in tree: %d\n",FindMin(root));
    printf("Max Element in tree: %d\n",FindMax(root));
}
