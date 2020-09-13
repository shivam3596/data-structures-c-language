#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

bool Search(struct Node* root,int number){
    if(root == NULL){
        return false;
    }else if(root->data == number){
        return true;
    }else if(number <= root->data){
        return Search(root->left,number);
    }else{
        return Search(root->right,number);
    }
}

void Print(struct Node *root, int space)
{
    if (root == NULL){
        return;
    }

    space += COUNT;

    Print(root->right, space);

    printf("\n");
    for (int i = COUNT; i < space; i++){
        printf(" ");
    }
    printf("%d\n", root->data);

    Print(root->left, space);
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

    printf("How Many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root, 0);

    int findNumber;
    printf("enter number you want to find");
    scanf("%d",&findNumber);

    if(Search(root,findNumber)){
        printf("Found!");
    }else{
        printf("Not Found!");
    }
}
