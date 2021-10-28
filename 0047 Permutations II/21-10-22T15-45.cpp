/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:

    void permute(size_t idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &nums){
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }

        for(size_t i = 0; i < arr.size(); ++i){
            if(arr[i] == -11){
                size_t j;
                for(j=i+1; j < arr.size(); ++j){
                    if(arr[j] == nums[idx]){
                        break;
                    }
                }
                if(j == arr.size()){
                    arr[i] = nums[idx];
                    permute(idx+1, arr, ans, nums);
                    arr[i] = -11;
                }
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans = {};
        vector<int> arr(nums.size(), -11);
        permute(0, arr, ans, nums);
        return ans;
    }
};
// @lc code=end

