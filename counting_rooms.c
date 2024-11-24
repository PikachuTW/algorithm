#include <stdbool.h>
#include <stdio.h>

int arr[1002][1002];
bool visited[1002][1002];

void dfs(int y, int x) {
    if (!arr[y][x]) return;
    if (visited[y][x]) return;
    visited[y][x] = true;
    dfs(y + 1, x);
    dfs(y - 1, x);
    dfs(y, x + 1);
    dfs(y, x - 1);
}

int main(void) {
    int height, width;
    scanf("%d%d", &height, &width);
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            char c = getchar();
            while (c == '\0' || c == '\n') c = getchar();
            if (c == '.') arr[y][x] = 1;
        }
    }
    int rooms = 0;
    for (int y = 1; y <= height; y++) {
        for (int x = 1; x <= width; x++) {
            if (!arr[y][x]) continue;
            if (!visited[y][x]) rooms += 1;
            dfs(y, x);
        }
    }
    printf("%d", rooms);
}