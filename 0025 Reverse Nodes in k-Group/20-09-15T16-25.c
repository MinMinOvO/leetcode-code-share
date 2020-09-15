/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode auxNode; auxNode.next = head;
    struct ListNode *a = &auxNode, *b = head, *c = head , *d = head->next, *e;
    int i = 0;
    while(d != NULL){
        if(++i == k){
            b->next = d;
            a = b;
            b = d;
            c = d;
            d = d->next;
            i = 0;
        }else{
            e = d->next;
            d->next = c;
            a->next = d;
            c = d;
            d = e;
        }
    }
    b->next = NULL;
    if(i != k-1){
        b = c->next;
        c->next = NULL;
        while(b != NULL){
            e = b->next;
            b->next = c;
            c = b;
            b = e;
        }
        a->next = c;
    }
    return auxNode.next;
}