#include <stdio.h>
#include <stdlib.h>

typedef struct Vector {
    int* content;
    int size;
} Vector;

void insert(Vector* vector, int value) {
    vector->size += 1;
    if (vector->size == 0) {
        vector->content = (int*)malloc(sizeof(int));
    } else {
        vector->content = (int*)realloc(vector->content, sizeof(int) * vector->size);
    }
    vector->content[vector->size - 1] = value;
}

Vector* directChildren[250000];
int childrens[250000];

void dfs(int value) {
    for (int i = 0; i < directChildren[value]->size; i++) {
        dfs(directChildren[value]->content[i]);
        childrens[value] += childrens[directChildren[value]->content[i]] + 1;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        directChildren[i] = (Vector*)malloc(sizeof(Vector));
        directChildren[i]->size = 0;
    }
    for (int i = 2; i <= n; i++) {
        int k;
        scanf("%d", &k);
        insert(directChildren[k], i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) {
        printf("%d ", childrens[i]);
    }
    for (int i = 1; i <= n; i++) {
        free(directChildren[i]->content);
        free(directChildren[i]);
        directChildren[i] = NULL;
    }
    return 0;
}