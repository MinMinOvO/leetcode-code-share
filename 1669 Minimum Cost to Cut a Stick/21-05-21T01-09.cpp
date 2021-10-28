#include <vector>
#include <algorithm>
class Solution {
public:
    #define INF 0x3f3f3f3f
    int minCost(int n, std::vector<int>& cuts) {
        int len_cuts = cuts.size();
        if(len_cuts == 1){
            return n;
        }
        std::vector<int> _cuts(cuts);
        std::sort(_cuts.begin(), _cuts.end());
        int cost[len_cuts][len_cuts];
        // cost[y][x] y: len_levely_segs-2 x:start from xth seg
        // note that for y, x_max + len_levely_segs = len_segs = len_cuts + 1
        cost[0][0] = _cuts[1];
        for(int i=0; i<len_cuts-2; i++){
            cost[0][i+1] = _cuts[i+2] - _cuts[i];
        }
        cost[0][len_cuts-1] = n - _cuts[len_cuts-2];
        for(int y=1; y<len_cuts; ++y){
            for(int x=0; x<len_cuts-y; ++x){
                int mincost = INF;
                for(int cut_offset=1; cut_offset < y+2; ++cut_offset){
                    int c;
                    if(cut_offset == 1){
                        c = 0;
                    }else{
                        c = cost[cut_offset-2][x];
                    }
                    if(cut_offset <= y){
                        c += cost[y-cut_offset][x+cut_offset];
                    }
                    if(mincost > c){
                        mincost = c;
                    }
                }
                int l;
                if(x+y+2 == len_cuts+1){
                    l = n;
                }else{
                    l = _cuts[x+y+2-1];
                }
                if(x != 0){
                    l -= _cuts[x-1];
                }
                cost[y][x] = mincost + l;
            }
        }
        return cost[len_cuts-1][0];
    }
};