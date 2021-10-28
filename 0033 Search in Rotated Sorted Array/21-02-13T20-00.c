

int search(int* nums, int numsSize, int target){
    int _lo = 0, _hi = numsSize-1, _m;
    while(_lo <= _hi){
        _m = (_lo + _hi) / 2;
        if(nums[_m] >= nums[0]){ //pivot on right
            if(target == nums[_m]){
                return _m;
            }else if(target < nums[_m] && nums[0] <= target){
                _hi = _m - 1;
                break;
            }else{
                _lo = _m + 1;
            }
        }else{//pivot on left
            if(target == nums[_m]){
                return _m;
            }else if(target > nums[_m] && nums[numsSize-1] >= target){
                _lo = _m + 1;
                break;
            }else{
                _hi = _m - 1;
            }
        }
    }
    while(_lo <= _hi){
        _m = (_lo + _hi) / 2;
        if(target < nums[_m]){
            _hi = _m - 1;
        }else if(target > nums[_m]){
            _lo = _m + 1;
        }else{
            return _m;
        }
    }
    return -1;
}