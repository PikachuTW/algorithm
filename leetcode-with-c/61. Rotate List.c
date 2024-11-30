/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head) return NULL;
    struct ListNode* ptr = head;
    int size = 1;
    while (ptr->next) {
        ptr = ptr->next;
        size += 1;
    }
    k = k % size;
    ptr->next = head;
    ptr = head;
    for (int i = 0; i < size - k - 1; i++) ptr = ptr->next;
    head = ptr->next;
    ptr->next = NULL;
    return head;
}