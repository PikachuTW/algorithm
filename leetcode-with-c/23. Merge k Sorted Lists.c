/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode beforehead;
    struct ListNode* ptr = &beforehead;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val > list2->val) {
            ptr->next = list2;
            list2 = list2->next;
        } else {
            ptr->next = list1;
            list1 = list1->next;
        }
        ptr = ptr->next;
    }
    ptr->next = list1 == NULL ? list2 : list1;
    return beforehead.next;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) return NULL;
    struct ListNode* list1 = lists[0];
    for (int i = 1; i < listsSize; i++) {
        list1 = mergeTwoLists(list1, lists[i]);
    }
    return list1;
}