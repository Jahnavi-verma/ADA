#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int find(int parent[], int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}

int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->w - ((struct Edge*)b)->w;
}

int main() {
    int V = 4;
    int E = 5;

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    qsort(edges, E, sizeof(edges[0]), cmp);

    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = i;

    printf("Edges in MST:\n");
    int totalWeight = 0, count = 0;

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        int pu = find(parent, u);
        int pv = find(parent, v);

        if (pu != pv) {
            printf("%d -- %d == %d\n", u, v, w);
            totalWeight += w;
            parent[pu] = pv;
            count++;
        }
    }

    printf("Total weight of MST: %d\n", totalWeight);

    return 0;
}