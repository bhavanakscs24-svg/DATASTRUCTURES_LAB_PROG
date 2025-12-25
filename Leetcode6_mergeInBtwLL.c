/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b,
                                struct ListNode* list2) {
    struct ListNode* curr = list1;
    for (int i = 0; i < a - 1; i++) {
        curr = curr->next;
    }
    struct ListNode* beforeA = curr;
    struct ListNode* afterB = curr->next;
    for (int i = a; i <= b; i++) {
        afterB = afterB->next;
    }
    beforeA->next = list2;
    curr = list2;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = afterB;
    return list1;
}