// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* majorityElement(int* nums, int numsSize, int* returnSize) {
//     int assume1 = 0;
//     int assume2 = 0;
//     int count1 = 0;
//     int count2 = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == assume1) {
//             count1 += 1;
//         } else if (nums[i] == assume2) {
//             count2 += 1;
//         } else if (count1 <= 0) {
//             assume1 = nums[i];
//             count1 = 1;
//         } else if (count2 <= 0) {
//             assume2 = nums[i];
//             count2 = 1;
//         } else {
//             count1 -= 1;
//             count2 -= 1;
//         }
//     }
//     int check1 = 0;
//     int check2 = 0;
//     for (int i = 0; i < numsSize; i++) {
//         if (nums[i] == assume1) {
//             check1 += 1;
//         } else if (nums[i] == assume2) {
//             check2 += 1;
//         }
//     }
//     int arr[2] = {0};
//     *returnSize = 0;
//     if (check1 > numsSize / 3) {
//         arr[(*returnSize)++] = assume1;
//     }
//     if (check2 > numsSize / 3) {
//         arr[(*returnSize)++] = assume2;
//     }
//     int* returnArr = malloc(sizeof(int) * (*returnSize));
//     memmove(returnArr, arr, sizeof(int) * (*returnSize));
//     return returnArr;
// }

// hashmap method: any better?

#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

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
    return INT_MIN;
}

bool containsDuplicate(int* nums, int numsSize) {
    HashMap* map = calloc(1, sizeof(HashMap));
    for (int i = 0; i < numsSize; i++) {
        if (get(map, nums[i]) == INT_MIN) {
            set(map, nums[i], 1);
        } else {
            return true;
        }
    }
    return false;
}