//Thuy Tran
//Lab 12

#include <iostream>
#include <bits/stdc++.h>
#define MAX 5

void bellmanFord(int G[][3], int E, int V, int s) {
    int distance_list[V];
    for(int i = 0; i < V; ++i) {
        distance_list[i] = INT_MAX;
    }
    distance_list[s] = 0;
    for(int v = 0; v < V - 1; ++v) {
        for(int j = 0; j < E; ++j) {
            int v1 = G[j][0], w = G[j][2], v2 = G[j][1];
            if(distance_list[v1] + w < distance_list[v2]) {
                distance_list[v2] = distance_list[v1] + w;
            }
        }
    }
    
    for(int j = 0; j < E; ++j) {
        int v1 = G[j][0], w = G[j][2], v2 = G[j][1];
        if(distance_list[v1] + w < distance_list[v2]) {
            std::cout << "Graph contains negative weight cycle and do not print the shortest distance from the source to rest of the vertices";
        }
    }
    
    std::cout << "Vertex" << "\tDistance from source vertex\n";
    for(int v = 0; v < V; ++v) {
        std::cout << v << "\t" << distance_list[v] << std::endl;
    }
};

int main() {
    int V = 3;
    int E = 3;
    int s = 0;
    int G[E][3] = {{0, 1, 2}, {1, 2, -1}, {0, 2, 5}};
    bellmanFord(G, E, V, s);

    return 0;
}


