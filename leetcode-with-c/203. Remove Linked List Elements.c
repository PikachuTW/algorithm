/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode** indirect = &head;
    while (*indirect != NULL) {
        if ((*indirect)->val != val) {
            indirect = &((*indirect)->next);
        } else {
            struct ListNode* temp = *indirect;
            *indirect = (*indirect)->next;
            free(temp);
        }
    }
    return head;
}