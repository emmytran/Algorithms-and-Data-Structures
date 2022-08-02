//Thuy Uyen My Tran
//Lab 10 - DFS

#include <iostream>
#include <vector>

std::vector <int> adj[10];
bool visited[9];

void DFS_Util(bool visited[], std::vector<int> adj[], int u) {
    visited[u] = true;
    std::cout << u << " ";
    //Print the traversed node here
    for (int v : adj[u]) {
        if (visited[v] == false) {
            DFS_Util(visited, adj, v);
        }
    }
}
void DFS(std::vector<int> adj[], int N) {
    //Create G: the list of nodes, example: if number of nodes is 4, then G is [1, 2, 3, 4]
    int G[N];
    for (int i  = 0; i < N; i++) {
        G[i] = i + 1;
    }
    //Define visited vector of length equal to number of nodes for each values Visited Vector
    for (int x : G) {
        visited[x] = false;
    }
    
    for (int u : G) {
        if (visited[u] == false) {
            DFS_Util(visited, adj, u);
        }
    }

}

void insertEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int n = 9;
    insertEdge(adj, 1, 2);
    insertEdge(adj, 1, 3);
    insertEdge(adj, 1, 4);
    insertEdge(adj, 1, 5);
    insertEdge(adj, 2, 6);
    insertEdge(adj, 3, 6);
    insertEdge(adj, 4, 7);
    insertEdge(adj, 5, 7);
    insertEdge(adj, 6, 8);
    insertEdge(adj, 7, 8);
    insertEdge(adj, 8, 9);
    
    std::cout << "Depth First Search traversal: ";
    DFS(adj, n);
    std::cout << std::endl;
    
    return 0;
}
