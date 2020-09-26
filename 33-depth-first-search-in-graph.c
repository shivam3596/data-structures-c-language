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
    int visited[];
};

struct Node* CreateNewNode(int destination){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = destination;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int source, int destination){
    //create a newNode
    struct Node* newNode = CreateNewNode(destination);

    //set next of new node pointing to the source
    newNode->next = graph->array[source].head;
    //set head of the source pointing to the new node
    graph->array[source].head = newNode;
}

struct Graph* CreateGraph(int numberOfVertices){
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    struct AdjList* arrayList = (struct AdjList*)malloc(numberOfVertices*sizeof(struct AdjList));

    graph->numberOfVertices = numberOfVertices;
    graph->array = arrayList;

    //mark head as null for all array lists and visited as false
    for(int i=0; i<numberOfVertices; i++){
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void PrintGraph(struct Graph* graph){
    for(int i=0; i< graph->numberOfVertices; i++){
        struct Node* temp = graph->array[i].head;
        printf("for head %d\n",i);
        while(temp){
            printf("-> %d",temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

void DepthFirstSearch(struct Graph* graph,int startVertex){
    //mark startVertex as visited and print it
    graph->visited[startVertex] = 1;
    printf("%d",startVertex);

    struct Node* temp = graph->array[startVertex].head;

    while(temp != NULL){
        int adjVertex = temp->data;

        if(graph->visited[adjVertex] == 0){
            DepthFirstSearch(graph,adjVertex);
        }
        temp = temp->next;
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

    DepthFirstSearch(graph,startVertex);
}
