#define MOD 2081

typedef struct {
    int key;
    int value;
} Pair;

typedef struct {
    Pair* table[MOD];
    int tableSize[MOD];
} MyHashMap;

MyHashMap* myHashMapCreate() {
    MyHashMap* myhashmap = calloc(1, sizeof(MyHashMap));
    return myhashmap;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int hash = key % MOD;
    if (obj->table[hash] == NULL) {
        obj->table[hash] = malloc(sizeof(Pair));
    } else {
        int exist = 0;
        for (int i = 0; i < obj->tableSize[hash]; i++) {
            if (obj->table[hash][i].key == key) {
                obj->table[hash][i].value = value;
                return;
            };
        }
        obj->table[hash] = realloc(obj->table[hash], (obj->tableSize[hash] + 1) * sizeof(Pair));
    }
    obj->table[hash][obj->tableSize[hash]++] = (Pair){.key = key, .value = value};
}

int myHashMapGet(MyHashMap* obj, int key) {
    int hash = key % MOD;
    if (obj->table[hash] != NULL) {
        for (int i = 0; i < obj->tableSize[hash]; i++) {
            if (obj->table[hash][i].key == key) return obj->table[hash][i].value;
        }
    }
    return -1;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int hash = key % MOD;
    if (obj->table[hash] != NULL) {
        for (int i = 0; i < obj->tableSize[hash]; i++) {
            if (obj->table[hash][i].key == key) {
                for (int p = i; p < obj->tableSize[hash] - 1; p++) {
                    obj->table[hash][p] = obj->table[hash][p + 1];
                }
                obj->tableSize[hash] -= 1;
                return;
            }
        }
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < MOD; i++) {
        if (obj->table[i] != NULL) free(obj->table[i]);
    }
    free(obj);
    obj = NULL;
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);

 * int param_2 = myHashMapGet(obj, key);

 * myHashMapRemove(obj, key);

 * myHashMapFree(obj);
*/