/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* Merge two sorted lists */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }
    tail->next = (l1) ? l1 : l2;
    return dummy.next;
}

/* Sort list using merge sort */
struct ListNode* sortList(struct ListNode* head) {
    if (!head || !head->next)
        return head;

    /* Find middle using slow/fast pointers */
    struct ListNode *slow = head, *fast = head, *prev = NULL;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    /* Split the list into two halves */
    prev->next = NULL;

    /* Recursively sort both halves */
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(slow);

    /* Merge sorted halves */
    return merge(left, right);
}
