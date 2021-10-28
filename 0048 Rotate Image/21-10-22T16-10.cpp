class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t N = matrix.size();
        for(size_t layer=0; layer<N/2; ++layer){
            for(size_t i=layer; i<N-layer-1; ++i){
                size_t y = layer, x=i;
                size_t j = 0;
                int foo = matrix[y][x];
                int bar;
                while(j < 4){
                    size_t tmp = x;
                    x = N-1-y;
                    y = tmp;
                    
                    bar = matrix[y][x];
                    matrix[y][x] = foo;
                    foo = bar;
                    
                    ++j;
                }
            }
        }
    }
};