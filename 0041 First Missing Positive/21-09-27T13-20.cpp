class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++) {
            while(0 < nums[i] and nums[i] <= nums.size() and nums[i] != nums[nums[i]-1]){
                int tmp = nums[i];
                nums[i] = nums[nums[i]-1];
                nums[tmp-1] = tmp;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return nums.size()+1;
    }
};