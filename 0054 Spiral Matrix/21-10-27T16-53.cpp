class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans = {};
        size_t m = matrix.size();
        size_t n = matrix[0].size();
        int y=0, x=0;
        int layer = 0;
        while(true){
            while(x < n - 1){
                ans.push_back(matrix[y][x]);
                x += 1;
            }// x == n - 1
            while(y < m - 1){
                ans.push_back(matrix[y][x]);
                y += 1;
            }// y == m - 1
            if(m - 1 == layer){
                ans.push_back(matrix[y][x]);
                break;
            }
            while(x > layer){
                ans.push_back(matrix[y][x]);
                x -= 1;
            }// x == layer
            if(n - 1 == layer){
                ans.push_back(matrix[y][x]);
                break;
            }
            while(y > layer){
                ans.push_back(matrix[y][x]);
                y -= 1;
            }// y == layer
            
            //update
            y += 1;
            x += 1;
            layer += 1;
            m -= 1;
            n -= 1;
            
            if(layer > m - 1 or layer > n - 1){
                break;
            }
        }
        return ans;
    }
};