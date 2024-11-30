// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     struct ListNode *next;
//  * };
//  */
// struct ListNode* deleteDuplicates(struct ListNode* head) {
//     int lastVal = -10000;
//     struct ListNode** indirect = &head;
//     while ((*indirect) != NULL) {
//         if (((*indirect)->next && (*indirect)->val == (*indirect)->next->val) || (*indirect)->val == lastVal) {
//             lastVal = (*indirect)->val;
//             struct ListNode* temp = *indirect;
//             *indirect = (*indirect)->next;
//             free(temp);
//         } else {
//             lastVal = (*indirect)->val;
//             indirect = &((*indirect)->next);
//         }
//     }
//     return head;
// }

// second solution (better)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* cur = head;
    while (cur != NULL) {
        if (cur->next != NULL && cur->val == cur->next->val) {
            while (cur->next != NULL && cur->val == cur->next->val) {
                struct ListNode* temp = cur;
                cur = cur->next;
                free(temp);
            }
            prev->next = cur->next;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }
    return dummy.next;
}