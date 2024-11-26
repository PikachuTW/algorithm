#include <stdio.h>
#include <stdlib.h>

#define ABS(a) ((a) > 0 ? (a) : (a) * -1)

int comp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int main(void) {
    int a, b, dif;
    scanf("%d%d%d", &a, &b, &dif);
    int* arrA = (int*)malloc(a * sizeof(int));
    int* arrB = (int*)malloc(b * sizeof(int));
    for (int i = 0; i < a; i++) {
        scanf("%d", &arrA[i]);
    }
    for (int i = 0; i < b; i++) {
        scanf("%d", &arrB[i]);
    }
    qsort(arrA, a, sizeof(int), comp);
    qsort(arrB, b, sizeof(int), comp);
    int* ptrA = arrA;
    int* ptrB = arrB;
    int ans = 0;
    while (1) {
        if ((ptrA - arrA) >= a || (ptrB - arrB) >= b) break;
        if (ABS(*ptrA - *ptrB) <= dif) {
            ptrA += 1;
            ptrB += 1;
            ans += 1;
        } else {
            if (*ptrA < *ptrB) {
                ptrA += 1;
            } else {
                ptrB += 1;
            }
        }
    }
    printf("%d", ans);
    return 0;
}