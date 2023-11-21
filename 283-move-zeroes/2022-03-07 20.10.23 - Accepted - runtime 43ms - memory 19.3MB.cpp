class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int w = 0;
        for(int i=0; i < n; i++){
            if(nums[i] != 0){
               nums[w++]=nums[i]; 
            }
        }
        for(int i = w; i < n; i++) nums[i] = 0;
    }
};