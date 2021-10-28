class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i_l = 0, i_r = nums.size()-1;
        while(i_l <= i_r and nums[i_l] == 0){
            i_l += 1;
        }
        while(i_r >= i_l and nums[i_r] == 2){
            i_r -= 1;
        }
        int i_e = i_l;
        int e;
        while(i_e <= i_r){
            e = nums[i_e];
            if(e == 0){
                if(i_e == i_l){
                    i_e += 1;
                    i_l += 1;
                }else{
                    nums[i_e] = nums[i_l];
                    nums[i_l] = e;
                    i_l += 1;
                }
            }else if(e == 1){
                i_e += 1;
            }else{ // == 2
                nums[i_e] = nums[i_r];
                nums[i_r] = e;
                i_r -= 1;
            }
        }
    }
};