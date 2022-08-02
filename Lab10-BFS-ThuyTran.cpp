//Thuy Uyen My Tran
//Lab 11 - BFS

#include <iostream>
#include <vector>
#include <list>

std::vector <int> adj[10];
bool visited[10];

//Breath First Search function
void BFS(std::vector<int> adj[], int N, int u){
    std::list<int> queue;
    visited[u] = true;

    queue.push_back(u);

    while(!queue.empty()) {
        u = queue.front();
        std::cout << u << " ";
        queue.pop_front();
        //Print u required for the traversal
        visited[u] = true;
        for (int v: adj[u]){
            if (visited[v] == false){
                visited[v] = true;
                queue.push_back(v);
            }
        }
    }
}

//Function to add edge
void insertEdge(std::vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//Main
int main() {
    int N = 9;
    insertEdge(adj, 1, 2);
    insertEdge(adj, 8, 9);
    insertEdge(adj, 3, 4);
    insertEdge(adj, 4, 5);
    insertEdge(adj, 6, 7);
    insertEdge(adj, 5, 6);
    insertEdge(adj, 7, 8);
    insertEdge(adj, 2, 3);

    std::cout << "Breath First Search traversal: ";
    BFS(adj, N, 1);
    std::cout << std::endl;
    
    return 0;
}
