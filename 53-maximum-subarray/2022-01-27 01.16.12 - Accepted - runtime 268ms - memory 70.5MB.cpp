class Solution {
    vector<int> nums;
    int findBest(int left, int right){
        if (left > right) return INT_MIN;
        
        int mid = left + (right - left)/2;
        int bestLeft = 0;
        int bestRight = 0;
        int curr = 0;
        
        for(int i = mid-1; i >= left; i--){
            curr+=nums[i];
            bestLeft = max(bestLeft,curr);
        }
        
        curr = 0;
        for(int i = mid+1; i <= right; i++){
            curr+=nums[i];
            bestRight = max(bestRight,curr);
        }
        
        int best = nums[mid] + bestLeft + bestRight;
        int leftArray = findBest(left, mid-1);
        int rightArray = findBest(mid+1, right);
        return max(best,max(leftArray,rightArray));
    }
public:
    int maxSubArray(vector<int>& nums) {
        this->nums = nums;
        return findBest(0,nums.size()-1);
    }
};