struct ut_s
{
    int key;
    int cnt;
    UT_hash_handle hh;
};

int findLHS(int* nums, int numsSize)
{
    struct ut_s *t = NULL;
    struct ut_s *s, *tmp, *ss;
    for(int i=0; i<numsSize; i++)
    {
        HASH_FIND_INT(t, nums+i, s);
        if(s == NULL)
        {
            s = (struct ut_s *)malloc(sizeof(struct ut_s));
            s->key = nums[i];
            s->cnt = 1;
            HASH_ADD_INT(t, key, s);
        }
        else
        {
            s->cnt += 1;
        }
    }
    int max = 0;
    HASH_ITER(hh, t, s, tmp)
    {
        int new_key = s->key + 1;
        HASH_FIND_INT(t, &new_key, ss);
        if(ss != NULL && ss->cnt + s->cnt > max)
        {
            max = ss->cnt + s->cnt;
        } 
    }    
    HASH_ITER(hh, t, s, tmp)
    { 
        HASH_DEL(t, s);
        free(s);
    }
    return max;
}