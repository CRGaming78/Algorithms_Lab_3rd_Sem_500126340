#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Queue{
    int items[MAX];
    int front,rear;
};

struct Queue* createQueue(){
    struct Queue* q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->rear == -1;
}

void enqueue(struct Queue* q,int value){
    if(q->rear==MAX-1)
        return;
    if(q->front==-1)
        q->front=0;
    q->rear++;
    q->items[q->rear]=value;
}

int dequeue(struct Queue* q){
    int item;
    if(isEmpty(q)) {
        return -1; 
    } else {
        item = q->items[q->front];
        q->front++;
        if(q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return item;
    }
}

struct Graph{
    int adjMatrix[MAX][MAX];  
    int visited[MAX];         
    int vertices;
};

void createGraph(struct Graph* g,int vertices){
    g->vertices=vertices;
    for (int i=0;i<vertices;i++){
        for (int j=0;j<vertices;j++){
            g->adjMatrix[i][j]=0;
        }
        g->visited[i]=0;
    }
}

void addEdge(struct Graph* g, int src, int dest) {
    g->adjMatrix[src][dest]=1;
    g->adjMatrix[dest][src]=1;  
}

void DFS(struct Graph* g, int vertex){
    g->visited[vertex]=1;
    printf("%d ",vertex);
    for (int i=0; i<g->vertices;i++){
        if (g->adjMatrix[vertex][i]==1 && g->visited[i]==0){
            DFS(g,i);
        }
    }
}

void BFS(struct Graph* g,int startVertex){
    struct Queue* q=createQueue();
    g->visited[startVertex]=1;
    enqueue(q,startVertex);
    while (!isEmpty(q)){
        int currentVertex=dequeue(q);
        printf("%d ",currentVertex);
        for (int i=0;i<g->vertices;i++){
            if (g->adjMatrix[currentVertex][i]==1 && g->visited[i]==0){
                g->visited[i]=1;
                enqueue(q,i);
            }
        }
    }
}

int main(){
    int vertices,edges,src,dest,startVertex,choice;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);
    struct Graph g;
    createGraph(&g,vertices);
    printf("Enter the number of edges: ");
    scanf("%d",&edges);
    for (int i=0;i<edges;i++){
        printf("Enter edge (source and destination): ");
        scanf("%d %d",&src,&dest);
        addEdge(&g,src,dest);
    }
    printf("Enter starting vertex for traversal: ");
    scanf("%d",&startVertex);
    printf("Choose traversal algorithm:\n1. DFS\n2. BFS\n");
    scanf("%d",&choice);
    if (choice == 1) {
        printf("Depth-First Search starting from vertex %d:\n",startVertex);
        DFS(&g,startVertex);
    } else if (choice == 2) {
        printf("Breadth-First Search starting from vertex %d:\n",startVertex);
        BFS(&g,startVertex);
    } else {
        printf("Invalid choice!\n");
        return 1;
    }
    return 0;
}