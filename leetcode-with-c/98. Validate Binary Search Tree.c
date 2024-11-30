/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* root, int* min, bool* first) {
    if (root != NULL) {
        if (!check(root->left, min, first)) return false;
        if (*first) {
            *min = root->val;
            *first = false;
        } else {
            if (root->val <= *min) {
                return false;
            } else {
                *min = root->val;
            }
        }
        if (!check(root->right, min, first)) return false;
    }
    return true;
}

bool isValidBST(struct TreeNode* root) {
    bool first = true;
    int min;
    return check(root, &min, &first);
}