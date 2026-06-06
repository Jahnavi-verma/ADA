#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

void topologicalSort(int num_vertices, int adj_matrix[MAX_VERTICES][MAX_VERTICES]) {
    int in_degree[MAX_VERTICES] = {0};
    int topo_order[MAX_VERTICES];
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int count = 0;

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (adj_matrix[i][j] == 1) {
                in_degree[j]++;
            }
        }
    }

    for (int i = 0; i < num_vertices; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    while (front < rear) {
        int current_vertex = queue[front++];
        topo_order[count++] = current_vertex;

        for (int neighbor = 0; neighbor < num_vertices; neighbor++) {
            if (adj_matrix[current_vertex][neighbor] == 1) {
                in_degree[neighbor]--;
                
                if (in_degree[neighbor] == 0) {
                    queue[rear++] = neighbor;
                }
            }
        }
    }

    if (count != num_vertices) {
        printf("-1\n");
    } else {
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];

    if (scanf("%d", &num_vertices) != 1 || num_vertices > MAX_VERTICES) {
        return 1;
    }

    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            if (scanf("%d", &adj_matrix[i][j]) != 1) {
                return 1;
            }
        }
    }

    topologicalSort(num_vertices, adj_matrix);

    return 0;
}