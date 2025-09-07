// Enter number of vertices and edges: 5 6
// Enter 6 edges (u v):
// 0 1
// 1 2
// 2 3
// 3 1
// 3 4
// 0 4

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // omit this for directed graph
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int x : adj[i]) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
