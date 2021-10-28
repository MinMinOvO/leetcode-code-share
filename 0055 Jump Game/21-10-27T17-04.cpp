class Solution {
public:
    
    bool dp(vector<int> &nums, vector<int> &can, int idx){
        if(idx >= nums.size()) return false;
        if(idx == nums.size() - 1) return true;
        if(can[idx]){
            if(can[idx] == 1){
                return false;
            }else{
                return true;
            }
        }
        for(int i=1; i<=nums[idx]; ++i){
            if(dp(nums, can, idx+i)){
                can[idx] = 2;
                return true;
            }
        }
        can[idx] = 1;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        size_t N = nums.size();
        vector<int> can(N, 0);
        return dp(nums, can, 0);
    }
};