#include<stdio.h>
#include<stdlib.h>
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
    }else if(number < root->data){
        root->left = Insert(root->left,number);
    }else{
        root->right = Insert(root->right,number);
    }
    return root;
}

struct Node* FindMin(struct Node* root){
    if(root == NULL){
        printf("Tree is empty");
        return 0;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* Delete(struct Node* root, int number){
    if(root == NULL) return root;

    else if(number < root->data){
        root->left = Delete(root->left,number);
    }else if(number > root->data){
        root->right = Delete(root->right,number);
    }else{
        //case 1: no child
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }

        //case 2: 1 child

        else if(root->left == NULL){
            struct Node* temp = root;
            root = temp->right;
            free(temp);
        }else if(root->right == NULL){
            struct Node* temp = root;
            root = temp->left;
            free(temp);
        }

        //case 3: 2 children

        else{
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

void main(){
    struct Node* root = NULL;
    int total,i,number,deleteNumber;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    printf("enter the number you want to delete: ");
    scanf("%d",&deleteNumber);
    root = Delete(root,deleteNumber);

    Print(root,0);
}
