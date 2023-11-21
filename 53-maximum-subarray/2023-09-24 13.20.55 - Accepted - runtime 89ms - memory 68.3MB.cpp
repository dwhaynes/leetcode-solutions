class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsub = INT_MIN;
        int curr = 0;
        for(auto num: nums){
            curr += num;
            if(curr > maxsub) maxsub = curr;
            if(curr < 0) curr = 0;
        }
        return maxsub;
    }
};