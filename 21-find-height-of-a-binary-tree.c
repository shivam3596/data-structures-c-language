#include<stdio.h>
#include<stdlib.h>

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

int FindHeight(struct Node* root){
    int leftHeight,rightHeight;
    if(root == NULL){
        return -1;
    }
    leftHeight = FindHeight(root->left);
    rightHeight = FindHeight(root->right);

    if(leftHeight > rightHeight){
        return leftHeight+1;
    }else{
        return rightHeight+1;
    }
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
    printf("Height of the tree recursice approach: %d\n",FindHeight(root));
}
