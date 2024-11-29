/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* ptr = head;
    while (ptr && ptr->next) {
        if (ptr->val == ptr->next->val) {
            struct ListNode* temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
        } else {
            ptr = ptr->next;
        }
    }
    return head;
}