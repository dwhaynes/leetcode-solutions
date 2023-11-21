class Solution {
    int findBound(vector<int>& nums, int target, bool isFirst){
        int n = nums.size();
        int begin = 0, end = n-1;
        
        while(begin <= end){
            int mid = (begin + end)/2;
            
            if(nums[mid] == target){
                if(isFirst){
                    if (mid == begin || nums[mid-1] != target) return mid;
                    end = mid-1;
                } else {
                    if (mid ==  end || nums[mid+1] != target) return mid;
                    begin = mid+1;
                }
            } else if(nums[mid] > target){
                end = mid-1;
            } else {
                begin = mid+1;
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrence = findBound(nums,target,true);
        
        if(firstOccurrence == -1) return {-1,-1};
        
        int lastOccurrence = findBound(nums,target,false);
        return {firstOccurrence,lastOccurrence};
    }
};