#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int n;
    int **parent;
    int max_level;
} TreeAncestor;

TreeAncestor *treeAncestorCreate(int n, int *parents, int parentSize)
{
    TreeAncestor *obj = malloc(sizeof(TreeAncestor));
    obj->n = n;
    obj->parent = malloc(n * sizeof(int *));

    // Allocate parents
    int max_level = 32 - __builtin_clz(n) + 1;
    for (int i = 0; i < n; i++) {
        obj->parent[i] = malloc(max_level * sizeof(int));
        for (int j = 0; j < max_level; j++)
            obj->parent[i][j] = -1;
    }
    for (int i = 0; i < parentSize; i++)
        obj->parent[i][0] = parents[i];

    // Get parent array for each element
    for (int j = 1;; j++) {
        int quit = 1;
        for (int i = 0; i < parentSize; i++) {
            obj->parent[i][j] = obj->parent[i][j + (-1)] == -1
                                    ? -1
                                    : obj->parent[obj->parent[i][j - 1]][j - 1];
            if (obj->parent[i][j] != -1) quit = 0;
        }
        if (quit) break;
    }
    obj->max_level = max_level - 1;
    return obj;
}

int treeAncestorGetKthAncestor(TreeAncestor *obj, int node, int k)
{
    int max_level = obj->max_level;
    for (int i = 0; i < max_level && node != -1; ++i)
        if (k & (1 << i))
            node = obj->parent[node][i];
    return node;
}

void treeAncestorFree(TreeAncestor *obj)
{
    for (int i = 0; i < obj->n; i++)
        free(obj->parent[i]);
    free(obj->parent);
    free(obj);
}

int main() {
    int n = 7;
    int parents[] = {-1, 0, 0, 1, 1, 2, 2};

    TreeAncestor * obj = treeAncestorCreate(10, parents, n);
    printf("%d\n", treeAncestorGetKthAncestor(obj, 3, 1));
    printf("%d\n", treeAncestorGetKthAncestor(obj, 5, 2));
    printf("%d\n", treeAncestorGetKthAncestor(obj, 6, 3));
}