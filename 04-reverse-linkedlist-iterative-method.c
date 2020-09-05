
#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* Reverse(struct Node* head){
    struct Node* current,*previous,*next;
    current = head;
    previous = NULL;
    while(current != NULL){
        next = current->next; // save the address of the next node
        current->next = previous; // now set next field of the current node pointing to the previous node
        previous = current;
        current = next;
    }
    head = previous;
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
    head = Reverse(head);
    Print(head);
}
