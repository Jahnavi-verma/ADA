#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 999 
#define n 4 

int min(int d[], int visited[]) {
    int min = INT_MAX;
    int min_index = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && d[i] <= min) {
            min = d[i];
            min_index = i;
        }
    }

    return min_index;
}

void dijkstra(int cost[n][n], int source) {
    int dist[n];
    int visited[n];

    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[source] = 0;

    for (int j = 0; j < n - 1; j++) {
        int u = min(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (visited[v] != 1 && cost[u][v] != INF && dist[u] != INT_MAX &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    printf("\nShortest paths from vertex %d:\n", source);
    for (int i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }
}

int main() {
    int i, j, source;
    int cost[n][n];

    printf("Enter cost adjacency matrix (%dx%d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0 && i != j)
                cost[i][j] = INF;
        }
    }

    printf("Enter source vertex (0-%d): ", n - 1);
    scanf("%d", &source);

    dijkstra(cost, source);

    return 0;
}