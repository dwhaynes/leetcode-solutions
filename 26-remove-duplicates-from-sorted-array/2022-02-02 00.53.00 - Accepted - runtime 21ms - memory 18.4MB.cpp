class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return n;
        int k = 1;
        for(int i = 1; i < n; i++){
           if(nums[i] == nums[i-1]) continue;
            nums[k] = nums[i];
            k++;
        }
        return k;
    }
};