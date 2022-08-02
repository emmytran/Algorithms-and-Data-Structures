#include <iostream>

#define V 5
#define INT_MAX 1000000000

int parent_list[V];
int array_temp[V];

void printOutput(int output[][V]) {
  for (int i = 0; i < V; ++i) {
    for (int j = 0; j < V; ++j) {
      std::cout << output[i][j] << ' ';
    }
    std::cout << std::endl;
  }
}

int Find(int u) {
  while (parent_list[u] != u)
    u = parent_list[u];
  return u;
}

void Union(int u, int v) {
  int v1 = Find(u);
  int v2 = Find(v);
  if (v1 != v2)
    parent_list[v1] = v2;
}

void kruskalMST(int G[][V]) {

  int output_G[V][V];

  for (int i = 0; i < V * V; ++i)
    output_G[i / V][i % V] = 0;
  for (int u = 0; u < V; ++u)
    parent_list[u] = u;

  int edge_count = 0;
  while (edge_count < V - 1)
    {
      int min = INT_MAX, u = -1, v = -1;
      for (int i = 0; i < V; i++)
        {
          for (int j = 0; j < V; j++)
            {
              if (Find (i) != Find (j) && G[i][j] < min)
            {
              min = G[i][j];
              u = i;
              v = j;
            }
            }
        }
    Union (u, v);
    array_temp[edge_count] = u;
    printf("Edge %d - %d == %d\n",
               u, v, min);
    edge_count++;
    }
  
  for (int v = 0; v < V; v++) {
    output_G[array_temp[v]][parent_list[v]] = G[array_temp[v]][parent_list[v]];
    output_G[parent_list[v]][array_temp[v]] = G[parent_list[v]][array_temp[v]];
  }

  printOutput(output_G);
}

int main()
{
    int G[][V] = {
        { INT_MAX, 2, INT_MAX, 6, INT_MAX },
        { 2, INT_MAX, 3, 8, 5 },
        { INT_MAX, 3, INT_MAX, INT_MAX, 7 },
        { 6, 8, INT_MAX, INT_MAX, 9 },
        { INT_MAX, 5, 7, 9, INT_MAX },
    };
 
    kruskalMST(G);
 
    return 0;
}


