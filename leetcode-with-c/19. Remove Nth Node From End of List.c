/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* ptr = head;
    int size = 0;
    while (ptr != NULL) {
        size += 1;
        ptr = ptr->next;
    }
    struct ListNode** indirect = &head;
    for (int i = 0; i < size - n; i++) indirect = &((*indirect)->next);
    struct ListNode* temp = *indirect;
    *indirect = (*indirect)->next;
    free(temp);
    return head;
}