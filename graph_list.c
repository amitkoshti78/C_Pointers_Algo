//
// Created by Amit Koshti on 22/11/25.
//
// space complexity = O(V + 2E) undirected graphs
// space complexity = O(V + E) directed graphs
// time complexity = O(V + E)  where v = number of vertices and E = number of edges

#include <stdio.h>
#include <stdlib.h>

typedef struct Mapping {
    int node_value;
    int node_count;
} Mapping;

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
    int *visited;
};

typedef struct Queue {
  int items[100];
  int front;
  int rear;
} Queue;

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
    graph->no_vertices = total_vertices;


    graph->array = (struct AdjList*)calloc(graph->no_vertices , sizeof(struct AdjList));
    graph->visited = (int*)calloc(graph->no_vertices , sizeof(int));

    for (int i = 0; i < graph->no_vertices ; i++) {
        graph->array[i].head = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge to graph
//Constructing the graph
void addEdge(struct Graph* graph,  int src, int dest, int count_src, int count_dest) {  // src 2, dest = 3, 5
    //Add destination node to source
    struct Node* newNode = createNode(dest);   //3--> >NULL // 4 --> NULL // 2 --> NULL // 4 --> NULL // 5 --> NULL
    // 3 --> NULL
    newNode->next = graph->array[count_src].head; // head[0] = NULL; 3 --> NULL // 3 --> head [0] = NULL
    //  4 --> 3 --> NULL
    //head[1] = NULL //  2 --> head[1] = NULL
    // head [1] = 2 ; 4 --> head[1] = 2
    //head [1] = 2--> NULL; 5 --> head[1] = 2 --> NULL
    // head[2] = 1 --> NULL; 3 --> head[2] = 1 --> NULL
    graph->array[count_src].head = newNode; // head[0] = 3  // head[0] = 4 --> 3 --> NULL
    //head[1] = 2 --> NULL
    //head[1] = 4 --> 2 --> NULL
    //head[1] = 5 --> 2 --> NULL
    //head[2] = 3 --> 1 --> NULL

    //Add source node to destination
    newNode = createNode(src);    // 0 --> NULL // 0 --> NULL // 1 --> NULL // 1 --> NULL // 1 --> NULL
    // 2 --> NULL
    newNode->next = graph->array[count_dest].head; // head[3] = NULL; 0 --> NULL
    // head[4] --> NULL , 0 --> head[4] --> NULL
    // head [2] = NULL // 1 --> head[2] = NULL
    // head[4] = 0 --> NULL  1 --> head[4] = 0 --> NULL
    // head[5] =NULL; 1 --> head[5] = NULL
    // head[3] = NULL; 2 --> head[3] = NULL
    graph->array[count_dest].head = newNode; // head[3] = 0 // head[4] = 0 --> NULL
    // head[2] = 1 --> NULL
    // head[4] = 1 --> 0 --> NULL
    // head[5] = 1 --> NULL
    // head[3] = 2 --> NULL
}

// Print graph [ 0   1   2   3   4   5]   10 91 78 18 24
//           i=  0   1   2   3   4   5
void printGraph(struct Graph* graph, Mapping map_arr[]) {
    for (int i = 1; i < graph->no_vertices; i++) {
        struct Node* temp = graph->array[i].head;
        printf("%d: %d --> : ", i, map_arr[i].node_value);
        while (temp) {
            printf("%d --> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL \n");
    }
}

//DFS traversal
void DFS_traversal(struct Graph* graph, int start_vertx, Mapping map_array[], int vertices_count) {
    int count_src;
    for (int k = 1; k < vertices_count; k++) {
        if (map_array[k].node_value == start_vertx) {  //struct map_array[1] = 56, 1 struct map_array[2] = 78, 2
            count_src = map_array[k].node_count;  // 2, 5, 4
        }
    }
    graph->visited[count_src] = 1; // graph->visited[2] = 1 78 visited[2]  1 81 visited[5] 1 33 visited[4]

    printf("\n Node : %d, visited : %d ", start_vertx, graph->visited[count_src]); // 78, 81, 33
    struct Node* temp = graph->array[count_src].head;
    while (temp) {
        for (int k = 1; k < vertices_count; k++) {
            if (map_array[k].node_value == temp->vertex) {  // 81 33,
                count_src = map_array[k].node_count; // 5  4 5
            }
        }
        if (graph->visited[count_src] == 0) {  // 5 -> 81 --> 1
            //printf("\n Node : %d, visited : %d ", temp->vertex, graph->visited[count_src]);
            DFS_traversal(graph, temp->vertex, map_array, vertices_count); // temp->vertex = 81, 33
        }
        temp = temp->next;
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

Queue* createQueue() {
    Queue* queue = (Queue *)malloc(sizeof(Queue));
    queue->front = 0;
    queue->rear = -1;
    return queue;
}

int isEmpty(Queue* queue) {

    if (queue->rear < queue->front) {
        return 1; // true
    }
    return 0; // false

}

void enqueue(Queue* q, int value) {
    if (q->rear == 99) {
        printf("\n Queue is full");
        return;
    }
    q->rear++;
    q->items[q->rear] = value;

}

int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;

    int value = q->items[q->front++];
    if (q->front > q ->rear) {
        q->front = 0;
        q->rear = -1;
    }
    return value;
}

void printQueue(Queue* q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

void BFS_traversal(struct Graph* graph, int startVertex, Mapping map_array[], int vertices_count) {
    int vertex_pos, vertex_pos1;

    Queue* queue = createQueue();
    enqueue(queue, startVertex);     // Graph [10, 23, 45, 67, 89] queue[45]
    //[45]-->10-->23-->NULL [10]-->45-->67-->NULL [23]-->45-->NULL [67]-->10-->89--NULL

    for (int k = 1; k < vertices_count; k++) {
        if (map_array[k].node_value == startVertex) {  // 81 33,
            vertex_pos = map_array[k].node_count; // 5  4 5
        }
    }
    graph->visited[vertex_pos] = 1; // node [45, 1] = 1
    while (!isEmpty(queue)){
        int currentVertex = dequeue(queue);
        if (currentVertex == -1) {
            break;
        }//[45]
        printf("\n %d ", currentVertex);         // 45, 10, 23 67
        for (int k = 1; k < vertices_count; k++) {
            if (map_array[k].node_value == currentVertex) {  // 81 33,
                vertex_pos = map_array[k].node_count; // 5  4 5
            }
        }
        struct Node* temp  =  graph->array[vertex_pos].head;  // node 10 node 45 node 45 node 10
        while (temp) {
            int vertex = temp->vertex;   // value 10 23 45 67 45 10 89
            for (int k = 1; k < vertices_count; k++) {
                if (map_array[k].node_value == vertex) {  // 81 33,
                    vertex_pos1 = map_array[k].node_count; // 5  4 5
                }
            }
            if (graph->visited[vertex_pos1] == 0) {
                enqueue(queue, vertex); // queue [45, 10, 23, 67, 89] front 45, rear 10
                graph->visited[vertex_pos1] = 1;
                //printf("\n %d ", vertex); // node [10, 1] = 1 // node [23, 1] = 1 // node [67, 1] = 1 // node [89, 1] = 1
            }
            temp = temp->next;

        }

    }
    free(queue);
}

int main() {
    int vertices, edges;
    int count_src, count_dest;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    int vertices_count = vertices + 1;

    Mapping *map_array = (Mapping*)malloc(vertices * sizeof(Mapping));
    for (int j = 1; j < vertices_count; j++) {
        printf("\n Enter the vertices: ");
        scanf("%d", &map_array[j].node_value);
        printf("\n Enter the count: ");
        scanf("%d", &map_array[j].node_count);

    }

    struct Graph* graph = createGraph(vertices_count);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        for (int k = 1; k < vertices_count; k++) {
            if (map_array[k].node_value == src) {
                count_src = map_array[k].node_count;
            }
            if (map_array[k].node_value == dest) {
                count_dest = map_array[k].node_count;
            }
        }
        addEdge(graph, src  , dest, count_src, count_dest );
    }

    printGraph(graph, map_array);

    int start_vertex;
    printf("\nEnter the start vertex: ");
    scanf("%d", &start_vertex);

    printf("\nDFS traversal: ");
    //DFS_traversal(graph, start_vertex, map_array, vertices_count);

    printf("\nBFS traversal: ");
    BFS_traversal(graph, start_vertex, map_array, vertices_count);

    deleteGraph(graph);

    return 0;
}

//10 56 70 92 23
//1  2  3   4  5

//1: 10 --> 70 --> 92 --> 56
//2: 56 --> 10 --> 70 --> 23
//3: 70 --> 56 --> 10
//4: 92 --> 10 --> 23
//5: 23 --> 56 --> 92



