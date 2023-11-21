class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(),nums.end(),nums.begin(),plus<int>());
        return nums;
    }
};