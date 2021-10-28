class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int idx_maxval_start=0, idx_maxval_end=0;
        int maxval = height[0];
        for(int i=1; i<height.size(); i++){
            if(height[i] > maxval){
                maxval = height[i];
                idx_maxval_start = i;
                idx_maxval_end = i;
            } else if(height[i] == maxval){
                idx_maxval_end = i;
            }
        }
        std::vector<int> idx_nxt = {};
        std::stack<int> idx_stk = {};
        for(int i=idx_maxval_start; i>=0; i--){
            while(not idx_stk.empty() and height[idx_stk.top()] <= height[i]){
                idx_stk.pop();
            }
            idx_nxt.push_back(idx_stk.empty()? -1 : idx_stk.top());
            idx_stk.push(i);
        }
        int idx = 0;
        do{
            int end = idx_nxt[idx_nxt.size() - idx - 1];
            int val = height[idx];
            for(int i=idx+1; i<end; i++){
                ans += val - height[i];
            }
            idx = end;
        }while(idx >= 0);
        for(int i=idx_maxval_start+1; i<idx_maxval_end; i++){
            ans += maxval - height[i];
        }
        idx_nxt.clear();
        idx_stk = {};
        for(int i=idx_maxval_end; i<height.size(); i++){
            while(not idx_stk.empty() and height[idx_stk.top()] <= height[i]){
                idx_stk.pop();
            }
            idx_nxt.push_back(idx_stk.empty()? height.size() : idx_stk.top());
            idx_stk.push(i);
        }
        idx = height.size()-1;
        do{

            int end = idx_nxt[idx-idx_maxval_end];
            int val = height[idx];
            for(int i=end+1; i<idx; i++){
                ans += val - height[i];
            }
            idx = end;
        }
        while(idx < height.size());
        return ans;
    }
};