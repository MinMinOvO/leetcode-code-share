/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int *ptr_vals;

void traverseTree(struct TreeNode* root){
    *ptr_vals = root->val;
    ptr_vals++;
    if(root->left != NULL)
        traverseTree(root->left);
    if(root->right != NULL)
        traverseTree(root->right);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if(root == NULL)
    {
        *returnSize = 0;
        return NULL;
    }
    int *vals = (int *)malloc(1000 * sizeof(int));
    ptr_vals = vals;
    traverseTree(root);
    *returnSize = (int)(ptr_vals - vals);
    vals = realloc(vals, *returnSize * sizeof(int));
    return vals;
}