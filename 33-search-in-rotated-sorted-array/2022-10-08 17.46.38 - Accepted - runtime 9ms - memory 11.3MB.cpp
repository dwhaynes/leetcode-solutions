class Solution {
    vector<int> nums;
    int target;
    
    int rotate_index(int left,int right){
        if(nums[left] < nums[right]) return 0;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[mid+1]) return mid+1;
            else{
                if(nums[mid] < nums[left]) right = mid-1;
                else left = mid+1;
            }
        }
        return 0;
    }
    
    int search(int left,int right){
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] == target) return mid;
            else{
                if(target < nums[mid]) right = mid-1;
                else left = mid+1;
            }
        }
        return -1;
    }
public:
    int search(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        int n = nums.size();
        if(n == 1) return nums[0] == target ? 0 : -1;
        
        int index = rotate_index(0,n-1);
        if(nums[index] == target) return index;
        if(index == 0) return search(0,n-1);
        if(target < nums[0]) return search(index,n-1);
        return search(0,index);
    }
};