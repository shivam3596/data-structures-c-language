#include<stdio.h>
#include<stdlib.h>


//define structure of the node
struct Node{
    int data;
    struct Node* next;
};

void Print(struct Node* head){
    struct Node* first = head;

    if(head != NULL){
        do{
            printf("%d",head->data);
            head = head->next;
        }
        while(first != head);
        printf("\n");
    }
}

struct Node* GetNewNode(int number){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = number;
    newNode->next = NULL;
    return newNode;
}

struct Node* InsertNumber(struct Node* head, int number){
    struct Node* newNode = GetNewNode(number);
    struct Node* temp = head;

    //when there is atleast one node in list
    if(head != NULL){
        //traverse to the last node
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }else{
        //when there is no node in the list
        head = newNode;
        newNode->next = head;
    }
    return head;
}


void main(){
    struct Node* head = NULL; //empty head in begining
    int total,i,number;

    printf("How many numbers you want to insert?");
    scanf("%d",&total);

    for(i=0; i< total; i++){
        printf("enter a number");
        scanf("%d",&number);
        head = InsertNumber(head,number);
    }
    Print(head);
}
