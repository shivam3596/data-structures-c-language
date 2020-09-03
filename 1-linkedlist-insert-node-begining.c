#include<stdlib.h>
#include<stdio.h>

//define structure of the node
struct Node{
    int data; // stores the value
    struct Node* next; //stores the address of the next node
};

//function to insert value
//takes 2 arguments, pointer head and input value
//returns head pointer after insertion
struct Node* Insert(struct Node* head, int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(head != NULL) temp->next =head;
    head = temp;
    return head;
}

//fucntion to print list
//takes pointer head as argument
void Print(struct Node* head){
    printf("List is :");
    while(head != NULL){
        printf("%d",head->data);
        head = head->next;
    }
    printf("\n");
}

void main(){
    struct Node* head = NULL; //empty list in the begining
    printf("how many numbers?");
    int n,i,x;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        printf("enter the numner");
        scanf("%d",&x);
        head = Insert(head,x);
        Print(head);
    }
}

