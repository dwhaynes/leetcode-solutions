class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> arr{{0,0}};
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(!arr.count(sum%k)) arr[sum%k] = i+1;
            else if(arr[sum%k] < i) return true;
        }
        return false;
    }
};