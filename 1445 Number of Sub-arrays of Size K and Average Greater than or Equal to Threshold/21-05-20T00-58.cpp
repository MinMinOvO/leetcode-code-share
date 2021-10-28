class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum_threshold = k * threshold;
        int sum = std::accumulate(arr.begin(), arr.begin() + k, 0);
        int res = sum >= sum_threshold? 1 : 0;
        for(int i=0, j=k; j < arr.size(); ++i, ++j){
            sum = sum - arr[i] + arr[j];
            if(sum >= sum_threshold){
                res += 1;
            }
        }
        return res;
    }
};