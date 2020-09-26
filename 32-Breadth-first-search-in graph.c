#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 40

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;

bool IsEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

void Enqueue(int number,int total){
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

struct Node{
    int data;
    struct Node* next;
};

struct AdjList{
    struct Node* head;
};

struct Graph{
    int numberOfVertices;
    struct AdjList* array;
    int visited[];
};

struct Graph* CreateGraph(int numberOfVertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numberOfVertices = numberOfVertices;
    graph->array = (struct AdjList*)malloc(numberOfVertices * sizeof(struct AdjList));

    for(int i=0; i<numberOfVertices; i++){
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

struct Node* CreateNewNode(int destination){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int source, int destination){
    struct Node* newNode = CreateNewNode(destination);
    newNode->next = graph->array[source].head;
    graph->array[source].head = newNode;
}

void PrintGraph(struct Graph* graph){
    for(int i=0; i< graph->numberOfVertices; i++){
        struct Node* temp = graph->array[i].head;
        printf("for head %d",i);
        while(temp){
            printf("-> %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void BreadthFirstTraversal(struct Graph* graph, int startVertex, int total){
    //mark startVertex as visited and enqueue
    graph->visited[startVertex] = 1;
    Enqueue(startVertex,total);

    while(!IsEmpty()){
        int current = Queue[front];
        printf("%d",current);
        Dequeue(total);

        struct Node* temp = graph->array[current].head;

        while(temp != NULL){
            int adjVertex = temp->data;

            if(graph->visited[adjVertex] == 0){
                graph->visited[adjVertex] = 1;
                Enqueue(adjVertex,total);
            }
            temp = temp->next;
        }
    }
}

void main(){
    int numberOfVertices = 4;
    int startVertex = 2;
    struct Graph* graph = CreateGraph(numberOfVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    PrintGraph(graph);

    BreadthFirstTraversal(graph,startVertex,numberOfVertices);
}
