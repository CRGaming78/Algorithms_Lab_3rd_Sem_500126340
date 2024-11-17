#include <iostream>
#include <climits>
using namespace std;
#define INF INT_MAX

struct Edge {
    int src, dest, weight;
};

void dijkstra(int V, int E, Edge edges[], int src) {
    int dist[V];
    bool visited[V] = {false};
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int minDist = INF, u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        if (u == -1) break;
        visited[u] = true;
        for (int i = 0; i < E; i++) {
            if (edges[i].src == u) {
                int v = edges[i].dest, weight = edges[i].weight;
                if (!visited[v] && dist[u] != INF && dist[u] + weight < dist[v])
                    dist[v] = dist[u] + weight;
            }
        }
    }
    cout << "Dijkstra's Distances from Source " << src << ": ";
    for (int i = 0; i < V; i++)
        cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << " ";
    cout << endl;
}

bool bellmanFord(int V, int E, Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;
    for (int i = 1; i < V; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src, v = edges[j].dest, weight = edges[j].weight;
            if (dist[u] != INF && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i].src, v = edges[i].dest, weight = edges[i].weight;
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return false;
        }
    }
    cout << "Bellman-Ford Distances from Source " << src << ": ";
    for (int i = 0; i < V; i++)
        cout << (dist[i] == INF ? "INF" : to_string(dist[i])) << " ";
    cout << endl;
    return true;
}
int main() {
    int V, E, src;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    Edge edges[E];
    cout << "Enter edges in the format (src dest weight):\n";
    for (int i = 0; i < E; i++)
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    cout << "Enter source vertex: ";
    cin >> src;
    dijkstra(V, E, edges, src);
    bellmanFord(V, E, edges, src);
    return 0;
}
// One thing to remember Dijkstra algorithm can't handle negative values