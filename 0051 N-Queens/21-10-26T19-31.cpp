class Solution {
public:
    void dfs(int n, vector<vector<int>> &flag, vector<int> &stk, vector<vector<string>> &ans){
        if(stk.size() == n){
            vector<string> solution = {};
            for(int i=0; i<n; ++i){
                solution.push_back(string(n, '.'));
            }
            for(int i=0; i<n; ++i){
                int y = stk[i] / n;
                int x = stk[i] % n;
                solution[y][x] = 'Q';
            }
            ans.push_back(solution);
            return;
        }
        int idx = stk.empty()? 0 : stk.back() + 1;
        for(int i=idx / n; i<n; ++i){
            for(int j= i == idx/n? idx%n : 0; j<n; ++j){
                if(flag[i][j] > 0) continue;
                for(int k=0; k<n; ++k){
                    flag[i][k] += 1;
                    flag[k][j] += 1;
                }
                if(i >= j){
                    //l_diag_y = i-j l_diag_x = 0
                    for(int k=n-(i-j)-1; k>=0; --k){
                        flag[i-j+k][k] += 1;
                    }
                }else{
                    //l_diag_y = 0 l_diag_x = j-i
                    for(int k=n-(j-i)-1; k>=0; --k){
                        flag[k][j-i+k] += 1;
                    }
                }
                if(i + j < n){
                    // r_diag_y = 0 r_diag_x = i+j
                    for(int k=i+j; k>=0; --k){
                        flag[k][i+j-k] += 1;
                    }
                }else{
                    // r_diag_y = i+j-n+1 r_diag_x = n-1
                    for(int k=n-(i+j-n+1)-1; k>=0; --k){
                        flag[i+j-n+1+k][n-1-k] += 1;
                    }
                }
                stk.push_back(i*n + j);
                dfs(n, flag, stk, ans);
                stk.pop_back();
                for(int k=0; k<n; ++k){
                    flag[i][k] += -1;
                    flag[k][j] += -1;
                }
                if(i >= j){
                    //l_diag_y = i-j l_diag_x = 0
                    for(int k=n-(i-j)-1; k>=0; --k){
                        flag[i-j+k][k] += -1;
                    }
                }else{
                    //l_diag_y = 0 l_diag_x = j-i
                    for(int k=n-(j-i)-1; k>=0; --k){
                        flag[k][j-i+k] += -1;
                    }
                }
                if(i + j < n){
                    // r_diag_y = 0 r_diag_x = i+j
                    for(int k=i+j; k>=0; --k){
                        flag[k][i+j-k] += -1;
                    }
                }else{
                    // r_diag_y = i+j-n+1 r_diag_x = n-1
                    for(int k=n-(i+j-n+1)-1; k>=0; --k){
                        flag[i+j-n+1+k][n-1-k] += -1;
                    }
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans = {};
        vector<int> stk = {};
        vector<vector<int>> flag(n, vector<int>(n, 0));
        dfs(n, flag, stk, ans);
        return ans;
    }
};