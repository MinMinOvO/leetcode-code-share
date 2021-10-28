class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        int last_idx = nums.size()-1;
        for(int idx=nums.size()-2; idx>=0; idx--){
            if(nums[idx] + idx >= last_idx){
                last_idx = idx;
            }
        }
        return last_idx == 0;
    }
};