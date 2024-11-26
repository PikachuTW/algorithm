#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Color { RED,
             BLACK };

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    enum Color color;
} Node;

static void rightRotate(Node*);
static void leftRotate(Node*);
static void fix(Node*);
static Node* createNode(Node*, Node*);

Node* insert(int);
bool has(int);

Node* root = NULL;

static Node* createNode(Node* parent, Node* node) {
    if (parent == NULL) return node;
    if (node->value < parent->value) {
        parent->left = createNode(parent->left, node);
        parent->left->parent = parent;
    } else if (node->value > parent->value) {
        parent->right = createNode(parent->right, node);
        parent->right->parent = parent;
    }
    return parent;
}

static void rightRotate(Node* rightNode) {
    Node* leftNode = rightNode->left;
    // R跟Lr的關係建立
    rightNode->left = leftNode->right;
    if (leftNode->right != NULL) {
        leftNode->right->parent = rightNode;
    }
    // L跟R的parent的關係建立
    leftNode->parent = rightNode->parent;
    if (rightNode->parent == NULL) {
        root = leftNode;
    } else if (rightNode->parent->right == rightNode) {
        rightNode->parent->right = leftNode;
    } else {
        rightNode->parent->left = leftNode;
    }
    // LR的關係建立
    leftNode->right = rightNode;
    rightNode->parent = leftNode;
}

static void leftRotate(Node* leftNode) {
    Node* rightNode = leftNode->right;
    // L跟Rl的關係建立
    leftNode->right = rightNode->left;
    if (rightNode->left != NULL) {
        rightNode->left->parent = leftNode;
    }
    // R跟L的parent的關係建立
    rightNode->parent = leftNode->parent;
    if (leftNode->parent == NULL) {
        root = rightNode;
    } else if (leftNode->parent->right == leftNode) {
        leftNode->parent->right = rightNode;
    } else {
        leftNode->parent->left = rightNode;
    }
    // LR的關係建立
    rightNode->left = leftNode;
    leftNode->parent = rightNode;
}

Node* insert(int value) {
    if (has(value)) return NULL;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->parent = NULL;
    newnode->color = RED;

    root = createNode(root, newnode);
    fix(newnode);
    return newnode;
}

static void fix(Node* node) {
    // 兩個連續的red違反規則
    while (node != root && node->parent != NULL && node->parent->color == RED) {
        if (node->parent->parent->left == node->parent) {  // uncle在parent右邊
            Node* uncle = node->parent->parent->right;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    leftRotate(node);
                }
                node->parent->parent->color = RED;
                node->parent->color = BLACK;
                rightRotate(node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle != NULL && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    rightRotate(node);
                }
                node->parent->parent->color = RED;
                node->parent->color = BLACK;
                leftRotate(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void printInOrder(Node* node) {
    if (node == NULL) return;
    printInOrder(node->left);
    printf("%d\n", node->value);
    printInOrder(node->right);
}

bool has(int value) {
    Node* node = root;
    while (node != NULL) {
        if (node->value == value) return true;
        if (node->value < value) {
            node = node->right;
        } else {
            node = node->left;
        }
    }
    return false;
}

int main(void) {
    srand(time(0));
    for (int i = 0; i < 10000; i += 101) {
        Node* newnode = insert(rand() % 1000);
    }
    printInOrder(root);
    // TODO: Delete
}