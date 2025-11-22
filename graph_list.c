//
// Created by Amit Koshti on 22/11/25.
//
// space complexity = O(V + 2E) undirected graphs
// space complexity = O(V + E) directed graphs
// time complexity = O(V + E)  where v = number of vertices and E = number of edges

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct AdjList {
    struct Node* head;
};

struct Graph {
    int no_vertices;
    struct AdjList* array;
};

// Create new node/vertices
struct Node* createNode(int number) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = number;
    newNode->next = NULL;
    return newNode;
}

// Create new graph
struct Graph* createGraph(int total_vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->no_vertices = total_vertices + 1;


    graph->array = (struct AdjList*)calloc(graph->no_vertices , sizeof(struct AdjList));

    for (int i = 0; i < graph->no_vertices ; i++) {
        graph->array[i].head = NULL;
    }
    return graph;
}

// Add edge to graph
void addEdge(struct Graph* graph, int src, int dest) {
    //Add destination node to source
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    //Add source node to destination
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 1; i < graph->no_vertices; i++) {
        struct Node* temp = graph->array[i].head;
        printf("%d: ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void deleteGraph(struct Graph* graph) {
    for (int i = 0; i < graph->no_vertices; i++) {
        struct Node* temp = graph->array[i].head;
        while (temp) {
            struct Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph->array);
    free(graph);
}

int main() {
    int vertices, edges;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    struct Graph* graph = createGraph(vertices);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printGraph(graph);

    deleteGraph(graph);

    return 0;
}


