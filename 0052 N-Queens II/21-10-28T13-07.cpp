class Solution {
public:
    
    void dfs(int &size_solutions, int c, int r, int n, uint64_t mask){
        uint64_t update_mask = 1UL << c | 1UL << (n+(n-r)+c) | 1UL << (3*n+r+c);
        if(update_mask & mask) return;
        if(r == n-1){
            size_solutions += 1;
            return;
        }
        update_mask |= mask;
        for(int j=0; j<n; ++j){
            dfs(size_solutions, j, r+1, n, update_mask);
        }
    }

    int totalNQueens(int n){
        int ans = 0;
        for(int j=0; j<n; ++j)
            dfs(ans, j, 0, n, 0UL);
        return ans;
    }
};