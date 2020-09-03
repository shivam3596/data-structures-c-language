
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Delete(int p,struct Node* head){
    struct Node* temp1 = head;
    if(p == 1){
        head = temp1->next;
        free(temp1);
        return head;
    }
    for(int i=1; i < p-1; i++){
        temp1 = temp1->next;
    }

    struct Node* temp2 = temp1->next;
    temp1->next = temp2->next;
    free(temp2);
    return head;
}

void Print(struct Node* head){
    while (head != NULL){
        printf ("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* Insert(struct Node* head,int x,int n){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    //when need to insert at first position
    if(n==1){
        newNode->next = head;
        head = newNode;
        return head;
    }
    struct Node* temp = head;
    for(int i=1; i< n-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

void main(){
    struct Node* head = NULL; //empty list
    head = Insert(head,2,1);
    head = Insert(head,3,2);
    head = Insert(head,4,3);
    head = Insert(head,5,4);
    Print(head);
    int p;
    printf("enter the position you want to delete");
    scanf("%d",&p);
    head = Delete(p,head);
    Print(head);
}
