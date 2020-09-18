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

    printf("\n");
    Print(root->right,space);

    for(int i =0; i<space; i++){
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
        printf("Treee is empty");
        return 0;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

struct Node* Find(struct Node* root, int data){
    if(root == NULL){
        return NULL;
    }else if(data == root->data){
        return root;
    }else if(data < root->data){
        return Find(root->left,data);
    }else{
        return Find(root->right,data);
    }
}

struct Node* GetSuccessor(struct Node* root, int data){
    //search the data in tree
    struct Node* current = Find(root,data);
    if(current == NULL) return NULL;

    //case: 1 (node has right subtree), return the minimum value in the right subtree

    if(current->right != NULL){
        return FindMin(current->right);
    }else{

        //case 2: (no right subtree for the node) , return the deepest node for which the current node is in left
        struct Node* successor = NULL;
        struct Node* ancestor = root;

        while(ancestor != current){
            if(current->data < ancestor->data){
                successor = ancestor;
                ancestor = ancestor->left;
            }else{
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

void main(){
    struct Node* root = NULL;
    struct Node* successor = NULL;
    int total,i,number,successorNumber;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    printf("Enter the number of which you want inorder successor: ");
    scanf("%d",&successorNumber);

    successor = GetSuccessor(root,successorNumber);
    printf("Inorder successor is %d",successor->data);
}
