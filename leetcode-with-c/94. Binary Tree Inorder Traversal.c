/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

static void writeArr(struct TreeNode* root, int* arr, int* arrSize) {
    if (root != NULL) {
        writeArr(root->left, arr, arrSize);
        arr[(*arrSize)++] = root->val;
        writeArr(root->right, arr, arrSize);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = malloc(sizeof(int) * 100);
    int arrSize = 0;
    writeArr(root, arr, &arrSize);
    *returnSize = arrSize;
    return arr;
}