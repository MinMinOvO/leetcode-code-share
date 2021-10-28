class Solution {
public:
    
    void f(int idx, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &comb){
        if(target == 0){
            ans.push_back(comb);
            return;
        }
        if(idx == candidates.size()){
            return;
        }
        if(target >= candidates[idx]){
            comb.push_back(candidates[idx]);
            f(idx, candidates, target - candidates[idx], ans, comb);  
            comb.pop_back();
        }
        f(idx+1, candidates, target, ans, comb);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans = {};
        vector<int> comb = {};
        f(0, candidates, target, ans, comb);
        return ans;
    }
    
};