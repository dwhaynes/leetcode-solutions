class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int n = r;
        vector<int> res(nums.size());
        while(l <= r){
            if(nums[l]*nums[l] > nums[r]*nums[r]){
                res[n] = nums[l]*nums[l];
                l++;
            }else{
                res[n] = nums[r]*nums[r];
                r--;
            }
            n--;
        }
        return res;
    }
};