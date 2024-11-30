// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     struct TreeNode *left;
//  *     struct TreeNode *right;
//  * };
//  */
// struct TreeNode* sortedListToBST(struct ListNode* head) {
//     struct TreeNode* newtree = malloc(sizeof(struct TreeNode));
//     if (!head) return NULL;
//     if (!head->next) {
//         *newtree = (struct TreeNode){.val = head->val, .left = NULL, .right = NULL};
//         return newtree;
//     }
//     struct ListNode* slow = head;
//     struct ListNode* fast = head->next->next;
//     while (fast && fast->next) {
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     newtree->val = slow->next->val;
//     struct ListNode* right = slow->next->next;
//     slow->next = NULL;
//     newtree->left = sortedListToBST(head);
//     newtree->right = sortedListToBST(right);
//     return newtree;
// }

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// ofc better solution

struct TreeNode* buildTree(int left, int right, struct ListNode** cur) {
    if (left > right) return NULL;
    int mid = left + (right - left) / 2;
    struct TreeNode* newnode = malloc(sizeof(struct TreeNode));
    newnode->left = buildTree(left, mid - 1, cur);
    newnode->val = (*cur)->val;
    *cur = (*cur)->next;
    newnode->right = buildTree(mid + 1, right, cur);
    return newnode;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int size = 0;
    struct ListNode* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        size += 1;
    }
    return buildTree(0, size - 1, &head);
}