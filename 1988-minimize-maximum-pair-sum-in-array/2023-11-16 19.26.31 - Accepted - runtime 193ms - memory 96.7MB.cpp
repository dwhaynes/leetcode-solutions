class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxSum = 0;
        int l = 0;
        int r = nums.size()-1;
        while(l < r){
            int sum = nums[l]+nums[r];
            if (sum > maxSum) maxSum = sum;
            l++;
            r--;
        }
        return maxSum;
    }
};