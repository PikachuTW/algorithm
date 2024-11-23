#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct movie {
    int start, end;
} Movie;

int comp(const void* a, const void* b) {
    return (*(Movie*)a).end - (*(Movie*)b).end;
}

Movie movies[250000];

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &movies[i].start, &movies[i].end);
    }
    qsort(movies, n, sizeof(Movie), comp);
    int leaveTime = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (movies[i].start >= leaveTime) {
            leaveTime = movies[i].end;
            ans += 1;
        }
    }
    printf("%d", ans);
    return 0;
}