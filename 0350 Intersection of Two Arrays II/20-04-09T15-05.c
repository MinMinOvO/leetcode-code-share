struct counter {
    int key;                    /* key */
    int count;
    UT_hash_handle hh;         /* makes this structure hashable */
};


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    
    if(nums2Size < nums1Size)
    {
        int *tmp = nums1;
        nums1 = nums2;
        nums2 = tmp;
        int tmpi = nums1Size;
        nums1Size = nums2Size;
        nums2Size = tmpi;
    }
    
    struct counter *c = NULL;
    for(int i=0; i<nums1Size; i++)
    {
        int key = nums1[i];
        struct counter *s;
        HASH_FIND_INT(c, &key, s);
        if(s == NULL)
        {
            s = (struct counter *)malloc(sizeof(struct counter));
            s->key = key;
            s->count = 1;
            HASH_ADD_INT(c, key, s);
        }
        else
        {
            s->count += 1;
        }
    }
    int *ans = (int *)malloc(nums1Size * sizeof(int));
    int size = 0;
    for(int i=0; i<nums2Size; i++)
    {
        int key = nums2[i];
        struct counter *s;
        HASH_FIND_INT(c, &key, s);
        if(s != NULL && s->count > 0)
        {
            s->count -= 1;
            ans[size++] = key;
        }
    }
    struct counter *tmp, *current;
    HASH_ITER(hh, c, current, tmp) {
        HASH_DEL(c,current);
        free(current);
    }
    free(c);
    *returnSize = size;
    if(size == 0)
    {
        free(ans);
    }
    else
    {
        ans = realloc(ans,size * sizeof(int));
    }
    return ans;
}

