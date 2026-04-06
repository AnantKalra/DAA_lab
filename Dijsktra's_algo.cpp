#include <iostream>
#include <vector>

using namespace std;

int get_min_vertex(vector<int>& dist, vector<bool>& visited, int V) {
    int min_val = 999999;
    int min_index = -1;

    for (int i = 0; i < V; i++) {
        if (visited[i] == false && dist[i] < min_val) {
            min_val = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(vector<vector<int>>& graph, int V, int src) {
    vector<int> dist(V, 999999);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = get_min_vertex(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (visited[v] == false && graph[u][v] != 0 && dist[u] != 999999 && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "\nVertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t\t " << dist[i] << endl;
    }
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V, 0));

    cout << "Enter the Adjacency Matrix (" << V << "x" << V << "):\n";
    cout << "(Enter 0 if there is no edge between vertices)\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(graph, V, source);

    return 0;
}
