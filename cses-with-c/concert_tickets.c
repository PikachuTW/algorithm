#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key;
    int priority;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->priority = rand();
    newNode->count = 1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void split(Node* root, int key, Node** left, Node** right) {
    if (!root) {
        *left = *right = NULL;
    } else if (key < root->key) {
        split(root->left, key, left, &root->left);
        *right = root;
    } else {
        split(root->right, key, &root->right, right);
        *left = root;
    }
}

Node* merge(Node* left, Node* right) {
    if (!left || !right) return left ? left : right;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

Node* insert(Node* root, Node* node) {
    if (!root) return node;
    if (node->key == root->key) {
        root->count += 1;
    } else if (node->priority > root->priority) {
        split(root, node->key, &(node->left), &(node->right));
        return node;
    } else if (node->key < root->key) {
        root->left = insert(root->left, node);
    } else {
        root->right = insert(root->right, node);
    }
    return root;
}

Node* erase(Node* root, int key) {
    if (!root) return NULL;
    if (key < root->key) {
        root->left = erase(root->left, key);
    } else if (key > root->key) {
        root->right = erase(root->right, key);
    } else {
        if (root->count > 1) {
            root->count -= 1;
        } else {
            Node* merged = merge(root->left, root->right);
            free(root);
            return merged;
        }
    }
    return root;
}

bool findMaxLessAndEqual(Node* root, int key, int* result) {
    if (!root) return false;
    if (root->key > key) return findMaxLessAndEqual(root->left, key, result);
    *result = root->key;
    return findMaxLessAndEqual(root->right, key, result) || true;
}

int main(void) {
    int ticketNum, customerNum;
    scanf("%d%d", &ticketNum, &customerNum);
    Node* treap = NULL;
    while (ticketNum--) {
        int price;
        scanf("%d", &price);
        Node* newNode = createNode(price);
        treap = insert(treap, newNode);
    }
    while (customerNum--) {
        int will;
        scanf("%d", &will);
        int res = -1;
        if (findMaxLessAndEqual(treap, will, &res)) {
            printf("%d\n", res);
            treap = erase(treap, res);
        } else {
            printf("-1\n");
        }
    }
    return 0;
}