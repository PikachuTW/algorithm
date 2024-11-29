/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *swapPairs(struct ListNode *head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *ptr = &dummy;
    while (ptr->next && ptr->next->next) {
        struct ListNode *first = ptr->next;
        struct ListNode *second = ptr->next->next;
        first->next = second->next;
        second->next = first;
        ptr->next = second;
        ptr = first;
    }
    return dummy.next;
}