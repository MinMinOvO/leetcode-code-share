#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *_FL = (int *)malloc(sizeof(int) * 2);
    *returnSize = 2;
    // get F
    int _l, _r, _m;
    for(_l=0, _r=numsSize-1; _l <= _r; ){
        _m = (_l + _r) / 2;
        if(nums[_m] >= target){
            _r = _m - 1;
        }else{
            _l = _m + 1;
        }
    }
    if(_r >= -1){
        _FL[0] = _l;
    }else{
        _FL[0] = _FL[1] = -1;
        return _FL;
    }
    for(_l=0, _r=numsSize-1; _l <= _r; ){
        _m = (_l + _r) / 2;
        if(nums[_m] <= target){
            _l = _m + 1;
        }else{
            _r = _m - 1;
        }
    }
    if(_l <= numsSize && _FL[0] <= _r){
        _FL[1] = _r;
    }else{
        _FL[0] = _FL[1] = -1;
    }
    return _FL;
}