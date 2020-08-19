

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct segment_tree
{
    int lower;
    int upper;
    int val;
    struct segment_tree *left;
    struct segment_tree *right;
};

struct segment_tree * build_segment_tree(int lower, int upper)
{
    struct segment_tree *t = (struct segment_tree *)malloc(sizeof(struct segment_tree));
    t->lower = lower;
    t->upper = upper;
    t->val = 0;
    if(lower != upper)
    {
        int mid = (lower + upper) >> 1;
        t->left = build_segment_tree(lower, mid);
        t->right = build_segment_tree(mid+1, upper);
    }
    else
    {
        t->left = NULL;
        t->right = NULL;
    }
    return t;
}

void add_val(struct segment_tree *root, int val, int lower, int upper)
{
    if(lower == root->lower && upper == root->upper)
    {
        root->val += val;
        return;
    }
    int mid = root->lower + root->upper >> 1;
    if(lower <= mid && mid < upper)
    {
        add_val(root->left, val, lower, mid);
        add_val(root->right, val, mid+1, upper);
    }
    else if(lower <= mid)
    {
        add_val(root->left, val, lower, upper);
    }
    else
    {
        add_val(root->right, val, lower, upper);
    }
}

void get_booked(struct segment_tree *root, int val, int *booked, int *idx)
{
    if(root->left == NULL && root->right == NULL)
    {
        booked[(*idx)++] = val+root->val;
        return;
    }
    if(root->left != NULL)
    {
        get_booked(root->left, val + root->val, booked, idx);
    }
    if(root->right != NULL)
    {
        get_booked(root->right, val + root->val, booked, idx);
    }
}

void free_tree(struct segment_tree *root)
{
    if(root->left != NULL)
    {
        free_tree(root->left);
    }
    if(root->right != NULL)
    {
        free_tree(root->right);
    }
    free(root);
}

int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    struct segment_tree *root = build_segment_tree(1, n);
    for(int i=0; i<bookingsSize; i++)
    {
        int *arr = bookings[i];
        add_val(root, arr[2], arr[0], arr[1]);
    }
    int idx = 0;
    int *booked = (int *)malloc(n * sizeof(int));
    get_booked(root, 0, booked, &idx);
    free_tree(root);
    *returnSize = n;
    return booked;
}

