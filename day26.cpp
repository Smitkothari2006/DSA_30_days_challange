/*
    Problem: Detect a Cycle in an Undirected Graph

    You are given an undirected graph represented by an adjacency list. 
    Your task is to determine if the graph contains any cycle.
    
    A cycle is formed if you can traverse through a sequence of edges 
    that starts and ends at the same vertex, with at least one edge in between.

    Input:
    - An integer V representing the number of vertices in the graph.
    - A list of edges, where each edge connects two vertices of the graph.

    Output:
    - Return true if the graph contains a cycle, otherwise return false.

    Constraints:
    - 1 ≤ V ≤ 10^4
    - 0 ≤ E ≤ 10^4
    - The graph is undirected.
    - The graph may contain multiple edges between the same pair of nodes.
    - There are no self-loops.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to detect cycle using DFS
bool dfs(int node, int parent, vector<unordered_multiset<int>>& adj, vector<bool>& visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited)) return true;
        } else if (neighbor != parent) {
            // If visited and not parent, then cycle exists
            return true;
        }
    }
    return false;
}

// Function to check for cycles in undirected graph
bool containsCycle(int V, vector<pair<int, int>>& edges) {
    // Build adjacency list with multiset to allow parallel edges
    vector<unordered_multiset<int>> adj(V);

    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    vector<bool> visited(V, false);

    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    vector<pair<int, int>> edges;
    cout << "Enter edges (u v) one per line:\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        // Check for parallel edges (cycle of length 2)
        if (u == v) continue;  // Ignore self-loops

        edges.emplace_back(u, v);
    }

    bool hasCycle = containsCycle(V, edges);
    cout << (hasCycle ? "true" : "false") << endl;

    return 0;
}
