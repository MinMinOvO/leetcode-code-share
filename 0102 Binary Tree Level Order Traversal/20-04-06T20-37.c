/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Node {
    struct Node *next;
    struct TreeNode *val;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root)
    {
        *returnSize = 0;
        return NULL;
    }
    struct Queue q;
    q.head = q.tail= (struct Node *)malloc(sizeof(struct Node));
    q.head -> val = root;
    int len_cur = 1;
    int len_nex = 0;
    int **ans = (int **)malloc(1024 * sizeof(int *));
    *returnColumnSizes = (int *)malloc(1024 * sizeof(int));
    int level = 0;
    while(len_cur)
    {
        int *arr = (int *)malloc(len_cur * sizeof(int));
        for(int i=0; i < len_cur; i++)
        {
            struct Node *o = q.head;
            if(o->val->left)
            {
                len_nex++;
                struct Node *n = (struct Node *)malloc(sizeof(struct Node));
                n->val = o->val->left;
                n->next = NULL;
                q.tail->next = n;
                q.tail = q.tail->next;
            }
            if(o->val->right)
            {
                len_nex++;
                struct Node *n = (struct Node *)malloc(sizeof(struct Node));
                n->val = o->val->right;
                n->next = NULL;
                q.tail->next = n;
                q.tail = q.tail->next;
            }
            *(arr+i) = o->val->val;
            q.head = q.head->next;
            free(o);
        }
        *(*returnColumnSizes + level) = len_cur;
        len_cur = len_nex;
        len_nex = 0;
        *(ans+level) = arr;
        level++;
    }
    *returnSize = level;
    *returnColumnSizes = (int *)realloc(*returnColumnSizes, level * sizeof(int));
    return ans;
}

