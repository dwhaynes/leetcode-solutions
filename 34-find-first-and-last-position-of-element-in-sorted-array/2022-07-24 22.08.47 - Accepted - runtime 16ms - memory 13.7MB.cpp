class Solution {
    int find(vector<int>& nums, int target, bool first){
        int n = nums.size();
        int begin = 0, end = n-1;
        
        while(begin <= end){
            int mid = begin + (end-begin)/2;
            
            if(nums[mid] == target){
                if(first){
                    if(mid == begin || nums[mid-1] != target) return mid;
                    end = mid - 1;
                }else{
                    if(mid == end || nums[mid+1] != target) return mid;
                    begin = mid+1;
                }
            } else if(nums[mid] > target){
                end = mid - 1;
            } else{
                begin = mid + 1;
            }
        }
        return -1;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = find(nums,target,true);
        if (first == -1) return {-1,-1};
        int last = find(nums,target,false);
        return {first,last};
    }
};