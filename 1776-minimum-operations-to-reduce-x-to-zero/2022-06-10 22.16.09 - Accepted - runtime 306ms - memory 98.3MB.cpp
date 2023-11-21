class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        
        int maxi = -1;
        int left = 0;
        int current = 0;
        
        for(int right = 0; right < n; right++){
            current+=nums[right];
            while(current > total - x && left <= right){
                current-=nums[left];
                left++;
            }
            if(current == total - x) maxi = max(maxi,right-left+1);
        }
        return maxi  == -1 ? -1 : n-maxi;
    }
};