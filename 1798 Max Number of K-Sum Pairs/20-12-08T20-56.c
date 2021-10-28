// 1 <= k <= 10^9
// 1 <= nums[i] <= 10^9

struct counter{
    int num;
    int cnt;
    UT_hash_handle hh;
};

int maxOperations(int* nums, int numsSize, int k){
    struct counter *C = NULL, *s, *tmp, *s2;
    for(size_t i=0; i<numsSize; ++i){
        if(nums[i] < k){
            HASH_FIND_INT(C, nums+i, s);
            if(s == NULL){
                s = (struct counter *)malloc(sizeof(struct counter));
                s->num = nums[i];
                s->cnt = 1;
                HASH_ADD_INT(C, num, s);
            }else{
                s->cnt += 1;
            }
        }
    }
    int pair = 0;
    int ed = (k+1)/2;
    HASH_ITER(hh, C, s, tmp){
        if(s->num < ed){
            int qa = k - s->num;
            HASH_FIND_INT(C, &qa, s2);
            if(s2 != NULL){
                pair += s->cnt < s2->cnt? s->cnt : s2->cnt;
            }
        }else if(s->num + ed == k){
            pair += s->cnt / 2;
        }
    }
    HASH_ITER(hh, C, s, tmp){
        HASH_DEL(C, s);
        free(s);
    }
    return pair;
}