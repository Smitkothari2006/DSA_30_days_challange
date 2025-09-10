/*
    Problem: Find the Shortest Path in an Unweighted Graph

    Input:
    - An integer V representing the number of vertices.
    - A list of edges where each edge connects two vertices.
    - Two integers, start and end, representing the source and destination nodes.

    Output:
    - Return the shortest path length (number of edges) from start to end.
    - If there is no path, return -1.

    Edge Cases:
    - If start == end and there are no edges, return 0.
    - If there is no connection between start and end, return -1.
    - The graph is undirected and can contain multiple edges between the same pair of nodes.
    - There are no self-loops.

    Example:
    Input:
        V = 5
        Edges = [[0, 1], [0, 2], [1, 3], [2, 3], [3, 4]]
        start = 0
        end = 4
    Output:
        3
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

int shortestPath(int V, vector<vector<int>>& edges, int start, int end) {
    // Edge case: start and end are the same
    if (start == end) return 0;

    // Create adjacency list
    vector<vector<int>> adj(V);
    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // BFS setup
    vector<bool> visited(V, false);
    queue<pair<int, int>> q; // {node, distance}
    q.push({start, 0});
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (neighbor == end) return dist + 1;
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }

    // If end is not reachable
    return -1;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    vector<vector<int>> edges;
    cout << "Enter each edge as two integers u and v (0-based index):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    int start, end;
    cout << "Enter start node: ";
    cin >> start;
    cout << "Enter end node: ";
    cin >> end;

    // Validate node bounds
    if (start < 0 || start >= V || end < 0 || end >= V) {
        cout << "Invalid start or end node." << endl;
        return 1;
    }

    int result = shortestPath(V, edges, start, end);
    cout << "Shortest path length: " << result << endl;

    return 0;
}
