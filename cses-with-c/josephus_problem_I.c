#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head;
Node* tail;

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 1) {
        printf("1");
        return 0;
    }
    for (int i = n; i >= 1; i--) {
        Node* newNode = malloc(sizeof(Node));
        newNode->val = i;
        if (i == n) {
            newNode->next = newNode;
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }
    bool remove = false;
    while (head != NULL) {
        if (remove) {
            Node* temp = head->next;
            printf("%d ", head->val);
            free(head);
            head = temp;
        } else {
            Node* temp = head->next;
            tail->next = head;
            tail = head;
            tail->next = NULL;
            head = temp;
        }
        remove = !remove;
    }
    printf("%d", tail->val);
}