

int removeElement(int* nums, int numsSize, int val){
    if (numsSize == 0) return 0;
    int i = 0, j = numsSize-1;
    while(i < j){
        while(i < j && nums[i] != val){
            i++;
        }
        if(i >= j) break;
        while(i < j && nums[j] == val){
            j--;
        }
        if(i >= j) break;
        nums[i] = nums[j];
        i++; j--;
    }
    return i == j && nums[i] != val? i+1 : i;
}