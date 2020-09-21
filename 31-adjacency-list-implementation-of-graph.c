#include<stdio.h>
#include<stdlib.h>

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
};

struct Graph* CreateGraph(int numberOfVertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numberOfVertices = numberOfVertices;
    graph->array = (struct AdjList*)malloc(numberOfVertices * sizeof(struct AdjList));

    for(int i=0; i<numberOfVertices; i++){
        graph->array[i].head = NULL;
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

    //in undirected grapgh destination is also directed to source
    newNode = CreateNewNode(source);
    newNode->next = graph->array[destination].head;
    graph->array[destination].head = newNode;
}

void PrintGraph(struct Graph* graph){
    for(int i=0; i< graph->numberOfVertices; i++){
        struct Node* temp = graph->array[i].head;
        printf("\n Adjacency list of vertex %d\n head ", i);
        while(temp){
            printf("-> %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void main(){
    int numberOfVertices = 5;
    struct Graph* graph = CreateGraph(numberOfVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    PrintGraph(graph);
}
