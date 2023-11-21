class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m;
        while(l <= r){
            m = l + (r-l)/2;
            if (nums[m] == target) return m;
            if (nums[m] > target) r = --m;
            else l = ++m;
        }
        return l;
    }
};