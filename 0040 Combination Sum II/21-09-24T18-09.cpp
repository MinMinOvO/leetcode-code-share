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
        int groupsize = 1;
        while(idx+groupsize < candidates.size() and candidates[idx+groupsize] == candidates[idx]){
            groupsize++;
        }
        for(int size=0; size<=groupsize; size++){
            if(target >= candidates[idx] * size){
                if(size > 0){
                    comb.push_back(candidates[idx]);
                }
                f(idx+groupsize, candidates, target - candidates[idx] * size, ans, comb);
            }
        }
        for(int size=1; size<=groupsize; size++){
            if(target >= candidates[idx] * size){
                comb.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> _candidates = candidates;
        std::sort(_candidates.begin(), _candidates.end());
        vector<vector<int>> ans = {};
        vector<int> comb = {};
        f(0, _candidates, target, ans, comb);
        return ans;
    }
};