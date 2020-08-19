/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* middleNode(struct ListNode* head){
    struct ListNode *a, *b;
    for(a=head, b=head; a && a->next; a=a->next->next, b=b->next);
    return b;
}

