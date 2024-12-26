#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

typedef struct HashMap {
    Node* table[SIZE];
} HashMap;

unsigned int hash(int key) {
    unsigned hashed = (unsigned int)key % SIZE;
    if (hashed < 0) {
        hashed += SIZE;
    }
    return hashed;
}

void set(HashMap* map, int key, int value) {
    unsigned int hashed = hash(key);
    Node* cur = map->table[hashed];
    while (cur) {
        if (cur->key == key) {
            cur->value = value;
            return;
        }
        cur = cur->next;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = map->table[hashed];
    map->table[hashed] = newNode;
}

int get(HashMap* map, int key) {
    unsigned int hashed = hash(key);
    Node* cur = map->table[hashed];
    while (cur) {
        if (cur->key == key) {
            return cur->value;
        }
        cur = cur->next;
    }
    return -1;
}

int main(void) {
    HashMap* map = calloc(1, sizeof(HashMap));
    set(map, 1, 1);
    set(map, 2, 1);
    set(map, 3, 1);
    set(map, 4, 1);
    for (int i = 0; i < 10; i++) {
        if (get(map, i) == -1) {
            set(map, i, 1);
            printf("%d not dup\n", i);
        } else {
            printf("%d dup\n", i);
        }
    }
}