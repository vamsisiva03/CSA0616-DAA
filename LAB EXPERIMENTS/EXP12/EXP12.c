#include <stdio.h>

#define V 5
#define INF 99999

// ---------- Prim's Algorithm ----------
int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(int graph[V][V]) {
    int parent[V];
    int key[V];
    int mstSet[V];

    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("\nPrim's MST:\n");
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
}

// ---------- Kruskal's Algorithm ----------
struct Edge {
    int src, dest, weight;
};

int parent[V];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b) {
    parent[find(a)] = find(b);
}

void kruskal(struct Edge edges[], int E) {
    struct Edge temp;

    // Sort edges by weight
    for (int i = 0; i < E - 1; i++) {
        for (int j = i + 1; j < E; j++) {
            if (edges[i].weight > edges[j].weight) {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("\nKruskal's MST:\n");
    printf("Edge\tWeight\n");

    for (int i = 0; i < E; i++) {
        int u = find(edges[i].src);
        int v = find(edges[i].dest);

        if (u != v) {
            printf("%d - %d\t%d\n",
                   edges[i].src,
                   edges[i].dest,
                   edges[i].weight);
            unionSet(u, v);
        }
    }
}

int main() {
    int graph[V][V];

    printf("Enter 5x5 adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    primMST(graph);

    struct Edge edges[20];
    int E = 0;

    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[E].src = i;
                edges[E].dest = j;
                edges[E].weight = graph[i][j];
                E++;
            }
        }
    }

    kruskal(edges, E);

    return 0;
}