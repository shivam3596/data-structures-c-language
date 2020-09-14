#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
#define COUNT 10

struct Node* Queue[MAX_SIZE];
int front = -1;
int rear = -1;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

bool IsEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

void Enqueue(int* number,int total){
    //check if queue is full , if next element of rear is front then queue is full
    if((rear + 1)%total == front){
        printf("Queue is full!");
        return;
    }else if(IsEmpty()){
        front = 0;
        rear = 0;
    }else{
        rear = (rear+1)%total; //increment rear
    }
    Queue[rear] = number;
}

void Dequeue(int total){
    if(IsEmpty()){
        printf("queue is empty!");
        return;
    }else if(front == rear){ //check if there is only single element in queue
        front = -1;
        rear = -1;
    }else{
        front = (front+1)%total; //increment front
    }
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//breadth-first-traversal or level order traversal in a binary tree
void LevelOrderTraversal(struct Node* root,int total){
    if(root == NULL){
        return;
    }

    Enqueue(root,total);
    //while there is atleast one element in queue
    while(!IsEmpty()){
        struct Node* current = Queue[front];
        printf("%d - ",current->data);

        if(current->left != NULL){
            Enqueue(current->left,total);
        }
        if(current->right != NULL){
            Enqueue(current->right,total);
        }
        Dequeue(total);
    }
}

//insert node in tree
struct Node* Insert(struct Node* root,int number){
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

//print the structure of the tree
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

void main(){
    struct Node* root = NULL;
    int total,i,number;

    printf("How many characters you want to insert in tree?");
    scanf("%d",&total);

    for(i=0; i<total; i++){
        printf("enter the character: ");
        scanf("%d",&number);
        root = Insert(root,number);
    }
    Print(root,0);
    LevelOrderTraversal(root,total);
}
