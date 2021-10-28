class Solution {
public:
    
    void f(int n, int k, int s, vector<int> &stk, vector<vector<int>> &ans){
        if(stk.size() == k){
            ans.push_back(stk);
            return;
        }
        for(int i=s; i<n; ++i){
            stk.push_back(i+1);
            f(n, k, i+1, stk, ans);
            stk.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans = {};
        vector<int> stk = {};
        f(n, k, 0, stk, ans);
        return ans;
    }
};