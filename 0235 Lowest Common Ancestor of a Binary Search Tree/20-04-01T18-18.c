/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <string.h>

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode* stack[1024];
    struct TreeNode* stack_copy[1024];
    int top = -1;
    int top_copy = -1;
    struct TreeNode* o = root;
    while(o)
    {
        stack[++top] = o;
        o = o->left;
    }
    while(top >= 0)
    {
        o = stack[top];
        if(o == p || o == q)
        {
            if (top_copy == -1)
            {
                memcpy(stack_copy, stack, sizeof(struct TreeNode*)*(top+1));
                top_copy = top;
            }
            else
            {
                int idx;
                int top_min = top < top_copy? top : top_copy;
                for(idx=0; stack[idx] == stack_copy[idx] && idx <= top_min; idx++);
                return stack[idx-1];
            }
        }
        o = o->right;
        if (o)
        {
            while(o)
            {
                stack[++top] = o;
                o = o->left;
            }
        }
        else
        {
            while(o == stack[top]->right)
            {
                o = stack[top--];
            }
        }
    }
    return NULL;
}