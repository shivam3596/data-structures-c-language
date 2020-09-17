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

struct Node* FindMin(struct Node* root){
    if(root == NULL) return 0;

    while(root->left != NULL){
        root = root->left;
    }
    return root;
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

    //if node become unbalanced the there are 4 cases below

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

struct Node* Delete(struct Node* root,int number){
    if(root == NULL){
        return root;
    }

    if(number < root->data){
        root->left = Delete(root->left,number);
    }else if(number > root->data){
        root->right = Delete(root->right,number);
    }else{
        //case: 1 (No child)
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }

        //case 2: (1 child)
        else if(root->left == NULL){
            struct Node* temp = root;
            root = temp->right;
            free(temp);
        }else if(root->right == NULL){
            struct Node* temp = root;
            root = temp->left;
            free(temp);
        }

        //case 3: (2 childern)
        else{
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }

    }

    if(root == NULL){
        return root;
    }

    //update height
    root->height = FindHeight(root);

    //get balance factor
    int balance = GetBalance(root);

    //if node become unbalanced the there are 4 cases below

    //LL Case
    if(balance > 1 && number < GetBalance(root->left) >=0){
        return RightRotate(root);
    }

    //RR CAse
    if(balance < -1 && GetBalance(root->right) <=0){
        return LeftRotate(root);
    }

    //LR Case
    if(balance > 1 && GetBalance(root->left) <0){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }

    //RL Case
    if(balance < -1 && GetBalance(root->right) >0){
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
    int total,i,number,deleteNumber;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the number: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);

    printf("enter number to delete from tree: ");
    scanf("%d",&deleteNumber);

    root = Delete(root,deleteNumber);

    Print(root,0);
}
