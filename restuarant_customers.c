#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct time {
    int value;
    bool isArrive;
} Time;

int comp(const void* a, const void* b) {
    return (*(Time*)a).value - (*(Time*)b).value;
}

int main(void) {
    int n;
    scanf("%d", &n);
    Time* arr = (Time*)malloc(sizeof(Time) * n * 2);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].value);
        scanf("%d", &arr[n + i].value);
        arr[i].isArrive = true;
        arr[n + i].isArrive = false;
    }
    qsort(arr, n * 2, sizeof(Time), comp);
    int people = 0;
    int maxPeople = 0;
    for (int i = 0; i < n * 2; i++) {
        if (arr[i].isArrive) {
            people += 1;
            maxPeople = MAX(maxPeople, people);
        } else {
            people -= 1;
        }
    }
    printf("%d", maxPeople);
}