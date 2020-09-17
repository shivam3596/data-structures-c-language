#include<stdio.h>
#include<stdlib.h>
#define COUNT 10

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    int height;
};

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = NULL;
    return newNode;
}

int FindHeight(struct Node* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = FindHeight(root->left);
    int rightHeight = FindHeight(root->right);

    return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
}

int GetBalance(struct Node* root){
    if(root == NULL) return 0;
    return FindHeight(root->left) - FindHeight(root->right);
}

struct Node* RightRotate(struct Node* root){
    struct Node* temp1 = root->left;
    struct Node* temp2 = temp1->right;

    temp1->right = root;
    root->left = temp2;

    root->height = FindHeight(root);
    temp1->height = FindHeight(temp1);
    return temp1;
}

struct Node* LeftRotate(struct Node* root){
    struct Node* temp1 = root->right;
    struct Node* temp2 = temp1->left;

    temp1->left = root;
    root->right = temp2;

    root->height = FindHeight(root);
    temp1->height = FindHeight(temp1);
    return temp1;
}

struct Node* Insert(struct Node* root, int number){
    struct Node* newNode = GetNewNode(number);
    //insert simillar as BST
    if(root == NULL){
        root = newNode;
    }else if(number < root->data){
        root->left = Insert(root->left,number);
    }else if(number > root->data){
        root->right = Insert(root->right,number);
    }else{
        return root;
    }

    //update height
    root->height = FindHeight(root);
    //get balance factor
    int balance = GetBalance(root);

    //LL Case
    if(balance > 1 && number < root->left->data){
        return RightRotate(root);
    }

    //RR CAse
    if(balance < -1 && number > root->right->data){
        return LeftRotate(root);
    }

    //LR Case
    if(balance > 1 && number > root->left->data){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    //RL Case
    if(balance < -1 && number < root->right->data){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
}

void Print(struct Node* root, int space){
    if(root == NULL){
        return;
    }

    space += COUNT;

    printf("\n");

    Print(root->right,space);

    for(int i=0; i<space; i++){
        printf(" ");
    }

    printf("%d\n",root->data);
    Print(root->left,space);
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
}
