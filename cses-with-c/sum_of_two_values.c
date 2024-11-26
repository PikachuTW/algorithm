#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    int position;
} Node;

int comp(const void* a, const void* b) {
    return (*(Node*)a).value - (*(Node*)b).value;
}

int main(void) {
    int n, targetSum;
    scanf("%d%d", &n, &targetSum);
    Node* arr = (Node*)malloc(sizeof(Node) * n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        arr[i].position = i + 1;
    }
    qsort(arr, n, sizeof(Node), comp);
    int left = 0, right = n - 1;
    while (left < right) {
        int sum = arr[left].value + arr[right].value;
        if (sum == targetSum) {
            printf("%d %d", arr[left].position, arr[right].position);
            return 0;
        }
        if (sum > targetSum) {
            right -= 1;
        } else {
            left += 1;
        }
    }
    printf("IMPOSSIBLE");
    return 0;
}