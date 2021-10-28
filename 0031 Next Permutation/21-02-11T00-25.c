#define swap(a, b, tmp) do{tmp=a; a=b; b=tmp;} while(0)

void nextPermutation(int* nums, int numsSize){
    if(numsSize <= 1){
        return;
    }
    int _start = -1, t;
    for(int nums_prei = nums[numsSize-1], i=numsSize-2; i>=0; nums_prei=nums[i], --i){
        if(nums[i] < nums_prei){
            _start = i;
            t = nums[i];
            break;
        }
    }
    int tmp;
    if(_start == -1){
        for(int i=0, j=numsSize-1; i < j; ++i, --j){
            swap(nums[i], nums[j], tmp);
        }
        return;
    }
    int _lo, _hi;
    for(_lo=_start+1, _hi=numsSize-1; _lo < _hi;){
        int _m = (_lo + 1 + _hi) / 2;
        if(t < nums[_m]){
            _lo = _m;
        }else{
            _hi = _m - 1;
        }
    }
    //then nums[_lo] > t >= nums[_lo+1]
    swap(nums[_lo], nums[_start], tmp);
    for(int _i=_start+1, _j=numsSize-1; _i<_j; ++_i, --_j){
        swap(nums[_i], nums[_j], tmp);
    }
}