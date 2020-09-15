/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL) return NULL;
    struct ListNode *a, *b, *c, *newhead;
    newhead = head->next==NULL? head : head->next;
    struct ListNode auxNode;
    auxNode.next = head;
    a = &auxNode;
    while(1){
        b = a->next;
        if(b == NULL) break;
        c = b->next;
        if(c == NULL) break;
        a->next = c;
        b->next = c->next;
        c->next = b;
        a = b;
    }
    return newhead;
}