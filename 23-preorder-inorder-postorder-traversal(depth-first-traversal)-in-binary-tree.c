#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node{
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* GetNewNode(char letter){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = letter;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
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

    printf("%c\n",root->data);

    Print(root->left,space);
}

void PreOrder(struct Node* root){
    if(root == NULL) return;

    printf("%c",root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void InOrder(struct Node* root){
    if(root == NULL) return;

    InOrder(root->left);
    printf("%c",root->data);
    InOrder(root->right);
}

void PostOrder(struct Node* root){
    if(root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%c",root->data);
}

struct Node* Insert(struct Node* root, char letter){
    struct Node* newNode = GetNewNode(letter);
    if(root == NULL){
        root = newNode;
    }else if(letter <= root->data){
        root->left = Insert(root->left,letter);
    }else{
        root->right = Insert(root->right,letter);
    }
    return root;
}

void main(){
    struct Node* root = NULL;
    int total;
    char letter;

    printf("how many letters you want to insert in tree?");
    scanf("%d",&total);

    for(int i=0; i<total; i++){
        printf("enter letter: ");
        scanf(" %c",&letter);
        root = Insert(root,letter);
    }

    Print(root,0);

    PreOrder(root);
    printf("\n");

    InOrder(root);
    printf("\n");

    PostOrder(root);
}
