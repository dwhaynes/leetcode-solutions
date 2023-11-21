class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int l = 0;
        int minLen = INT_MAX;
        for(int r = 0; r < nums.size(); r++){
            sum += nums[r];
            while(sum >= target){
                minLen = min(minLen, r-l+1);
                sum -= nums[l++];
            }
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};